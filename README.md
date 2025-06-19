# Bankers Algorithm POC

Resource allocation and deadlock avoidance

## Key ideas

| OS                | Banks             |
|---------------    | ---------------   |
| Job               | Customer          |
| Devices Allocated | Loan Amount       |
| Max Required      | Max Credit        |
| Remaining needs   | Remaining Credit  |

- safe
- unsafe

- Disadvantages

# Algorithm

```brainfuck
let n = number of processes in the system (user input)

let available = number of available resources
let max = array[n]
let allocation = array[n]

let running = array[n]
let total_available = available - sum(allocation)

let at_least_one_alloc = false
while nonzero_count(running) > 0:
	at_least_one_alloc = false
	for p in range n:
		let needs = max[p] - allocation[p]
		if total_available - needs >= 0:
			at_least_one_alloc = true
			running[p] = 0 // Stop running process
			total_available += allocation[p] // Available resource increase because process are deallocated
	if at_least_one_alloc:
		print(safe)
	else
		print(unsafe)
```
