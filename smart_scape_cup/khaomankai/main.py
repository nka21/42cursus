import asyncio
import websockets
import json
import random
from solver import Solver, score, PERMS
from itertools import permutations

PORT_MASTER = 8088
URL         = f"ws://localhost:{PORT_MASTER}"
YOUR_NAME   = "Khaomankai"

def shuffle(arr):
	result = []
	arr = set(["".join(sorted(p)) for p in arr])
	for item in arr:
		perms = [''.join(p) for p in permutations(item)]
		result.extend(perms)
	return sorted(result)

def change(arr):
	result = set()
	for num_str in arr:
		digits = list(num_str)
		for i in range(4):
			original_digit = digits[i]
			for replacement in ('01234' if original_digit in '01234' else '56789'):
				if replacement == original_digit:
					continue
				if replacement in digits:
					continue
				new_digits = digits[:]
				new_digits[i] = replacement
				new_num = ''.join(new_digits)
				result.add(new_num)
	return sorted(result)

def generate_unique_4digit_number() -> str:
    digits = random.sample(range(10), 4)
    return ''.join(map(str, digits))

def make_response_PlayerName(player_name: str) -> str:
	response = {
		"messageType": "requestPlayerName",
		"body": {
			"playerName": player_name
		}
	}

	return json.dumps(response)

def make_response_SecretNumber(number: int) -> str:
	response = {
		"messageType": "requestSecretNumber",
		"body": {
			"number": str(number)
		}
	}

	return json.dumps(response)

def make_response_ItemAction() -> str:
	response = {
		"messageType": "requestItemAction-pass",
		"body": {
			"action": "pass"
		}
	}

	return json.dumps(response)


def make_response_ChallengeNumber(number_str: str) -> str:
	response = {
		"messageType": "requestChallengeNumber",
		"body": {
			"action": "call",
			"number": number_str
		}
	}

	return json.dumps(response)

def make_response_Target(digit: str) -> str:
	response = {
		"messageType": "requestItemAction-target",
		"body": {
			"action": "target",
			"number": digit
		}
	}
	return json.dumps(response)

def make_response_HighLow() -> str:
	response = {
		"messageType": "requestItemAction-high-low",
		"body": {
			"action": "high-low",
		}
	}
	return json.dumps(response)

def make_response_Shuffle(number_str: str) -> str:
	shuffled_number = random.choice(shuffle([number_str]))
	response = {
		"messageType": "requestItemAction-shuffle",
		"body": {
			"action": "shuffle",
			"number": shuffled_number
		}
	}
	return json.dumps(response),shuffled_number

def make_response_Change(number_str: str) -> str:
	changed_number = random.choice(change([number_str]))
	response = {
		"messageType": "requestItemAction-change",
		"body": {
			"action": "change",
			"number": changed_number
		}
	}
	return json.dumps(response),changed_number

async def main():
	try: 
		async with websockets.connect(URL) as websocket:
			print("起動!!")
			bot = Solver()
			challenge_number = None
			move = 0
			after_declear = False
			my_number = "0123"
			while True:
				message = await websocket.recv()
				data = json.loads(message)
				message_type = data.get("messageType")
				print(f"recv: {data}")
				response = None
				if message_type == "requestPlayerName":
					response = make_response_PlayerName(YOUR_NAME)
					await websocket.send(response)
				elif message_type == "requestSecretNumber":
					my_number = generate_unique_4digit_number()
					response = make_response_SecretNumber(my_number)
					await websocket.send(response)
				elif message_type == "requestChallengeNumber":
					challenge_number ,action = bot.next_move()
					move += 1
					after_declear = True
					response = make_response_ChallengeNumber(challenge_number)
					await websocket.send(response)
				elif message_type == "challengeResult":
					result = data.get("body").get("result")
					hit = result.get("hit")
					blow = result.get("blow")
					bot.update_feedback(challenge_number, (hit,blow))
				elif message_type == "opponentActionResult":
					action_result = data.get("body").get("actionResults")
					if any(item.get("action") == "shuffle" for item in action_result):
						bot.cand = shuffle(bot.cand)
					elif any(item.get("action") == "change" for item in action_result):
						bot.cand = change(bot.cand)
				elif message_type == "requestItemAction":
					if (move == 0) and (not after_declear):
						response = make_response_HighLow()
					elif (move == 1) and (not after_declear):
						response = make_response_Target(bot.choice_target())
					elif (move == 3) and (after_declear):
						response, my_number = make_response_Shuffle(my_number)
					elif(move == 4) and (after_declear):
						response, my_number = make_response_Change(my_number)
					else:
						response = make_response_ItemAction()
					after_declear = False
					await websocket.send(response)
				elif message_type == "itemActionResult-high-low":
					result = data.get("body").get("result")
					bot.update_highlow(result.get("high"),result.get("low"))
				elif message_type == "itemActionResult-target":
					result = data.get("body").get("result")
					bot.update_target(result.get("number"),result.get("position"))
				elif message_type == "roundResult":
					print("Round end-------------------------------")
					move = 0
					after_declear = False
					bot.reset()
				elif message_type == "gameResult":
					print("game set")
					return

				print(f"send: {response}")

	except json.JSONDecodeError:
		print("Invalid JSON received")
	except websockets.exceptions.ConnectionClosedError as e:
		print(f"Connection closed: {e}")
	except Exception as e:
		print(f"Unexpected error: {e}")

if __name__ == "__main__":
	asyncio.run(main())
