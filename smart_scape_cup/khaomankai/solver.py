#!/usr/bin/env python3
# 4-digit Hit&Blow solver (Knuth-lite), чистый Python, 1 файл

from itertools import permutations
import random
from collections import Counter

# --- precompute all 5040 возможных секретов -------------------------------
PERMS = [''.join(p) for p in permutations('0123456789', 4)]      # 5040 шт.

def score(secret: str, guess: str) -> tuple[int, int]:
    """Вернёт (hit, blow) для пары строк длиной 4 без повторов."""
    hit  = sum(a == b for a, b in zip(secret, guess))
    blow = len(set(secret) & set(guess)) - hit
    return hit, blow


class Solver:
    """
    «Практичный» бот:
    • пока cand > 300 — берём cand[0]  (фильтр-стратегия O(n));
    • иначе — minimax внутри cand (≤ 300² проверок);
    • триггер Target оставлен, но по умолчанию выключен.
    """

    def __init__(self) -> None:
        self.cand = PERMS.copy()      # оставшиеся возможные секреты
        self.turn = 0                 # номер хода (с 1)
        self.ap   = 0                 # Action Points
        self.used_target = False    # ← включите, если решите юзать Target

    # ---------- вспомогательные private-методы -----------------------------
    def reset(self):
        self.cand = PERMS.copy()

    def _best_guess_minimax(self) -> str:
        """
        Минимакс-оценка ТОЛЬКО внутри текущего cand.
        Для cand ≤ 300 работает < 10 мс даже на CPython.
        """
        best, best_worst = None, None
        for g in self.cand:
            buckets = {}
            for c in self.cand:
                fb = score(c, g)
                buckets[fb] = buckets.get(fb, 0) + 1
            worst = max(buckets.values())
            if best_worst is None or worst < best_worst:
                best, best_worst = g, worst
        return best

    # ---------- публичный API, вызываемый игровой ареной -------------------

    def next_move(self) -> tuple[str | None, tuple | None]:
        """
        Возвращает:
            guess : 4-симв. строка или None (если играем айтем)
            action: None либо ('Target', digit)
        """
        self.turn += 1
        self.ap   += 1            # +1 AP за каждый ход

        # --- (необязательный) триггер Target --------------------------------
        # if (not self.used_target
        #     and self.turn == 4
        #     and len(self.cand) > 200
        #     and self.ap >= 5):
        #     self.ap -= 5
        #     self.used_target = True
        #     digit = Counter(''.join(self.cand)).most_common(1)[0][0]
        #     return None, ('Target', digit)

        # --- обычная догадка -------------------------------------------------
        if len(self.cand) == 1:              # всё уже однозначно
            return self.cand[0], None

        if len(self.cand) > 2000:             # быстрый фильтр
            return self.cand[0], None

        return self._best_guess_minimax(), None

    # -----------------------------------------------------------------------

    def update_feedback(self, guess: str, fb: tuple[int, int]) -> None:
        """Фильтруем cand, оставляя только совместимые с полученным fb."""
        self.cand = [c for c in self.cand if score(c, guess) == fb]

    def update_target(self, digit: str, position: int) -> None:
        """
        Обновляем cand после ответа на Target:
          • position is None  → цифры digit точно нет в секрете
          • иначе            → digit стоит ровно на position
        """
        if position == -1:
            self.cand = [c for c in self.cand if digit not in c]
        else:
            self.cand = [c for c in self.cand if c[position] == digit]

    def update_highlow(self, high: int, low: int) -> None:
        filtered = []
        for num in self.cand:
            low_count = sum(1 for ch in num if ch in "01234")
            high_count = sum(1 for ch in num if ch in "56789")
            if high_count == high and low_count == low:
                filtered.append(num)
        self.cand = filtered

    def choice_target(self) -> str:
        min_score = 5040
        best_digit = "0"

        for d in "0123456789":
            cnt = [0] * 4
            for num in self.cand:
                for i in range(4):
                    if num[i] == d:
                        cnt[i] += 1
            cnt_no = len(self.cand) - sum(cnt)
            worst_case = max(max(cnt), cnt_no)

            if worst_case < min_score:
                min_score = worst_case
                best_digit = d

        return best_digit
