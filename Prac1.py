# // 1.BFS

graph = {
    0: [1, 2],
    1: [0, 3, 4],
    2: [0, 5],
    3: [1],
    4: [1],
    5: [2]
}

def bfs(start):
    visited = set()
    queue = [start]

    visited.add(start)

    while queue:
        node = queue.pop(0)
        print(node, end=" ")

        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)

print("BFS Traversal:")
bfs(0)




# 2.DFS 




graph = {
    5: [3, 7],
    3: [2, 4],
    7: [8],
    2: [],
    4: [],
    8: []
}

visited = set()

def dfs(node):
    if node not in visited:
        visited.add(node)

        print(node, end=" ")

        for neighbor in graph[node]:
            dfs(neighbor)

print("DFS Traversal:")
dfs(5)





# 3. A*




from queue import PriorityQueue

graph = {
    'A': [('B', 1), ('C', 2)],
    'B': [('D', 4)],
    'C': [('D', 1)],
    'D': []
}

heuristic = {
    'A': 3,
    'B': 2,
    'C': 1,
    'D': 0
}

pq = PriorityQueue()
pq.put((0, 'A'))

visited = []

print("A* Traversal:")

while not pq.empty():
    cost, node = pq.get()

    if node not in visited:
        visited.append(node)

        print(node, end=" ")

        for neighbor, weight in graph[node]:
            score = weight + heuristic[neighbor]
            pq.put((score, neighbor))




# 4.Shopping Chatbot




while True:
    print("\n1. Product Search")
    print("2. Order Tracking")
    print("3. Return Policy")
    print("4. Payment Methods")
    print("5. Exit")

    choice = input("Enter choice: ")

    if choice == "1":
        print("Available Products: Shoes, Laptop, Watch")

    elif choice == "2":
        order = input("Enter Order ID: ")
        print("Order", order, "is shipped")

    elif choice == "3":
        print("Return allowed within 7 days")

    elif choice == "4":
        print("UPI, Card, Net Banking")

    elif choice == "5":
        print("Chatbot Closed")
        break

    else:
        print("Invalid Choice")




# 5.Railway Chatbot



while True:
    print("\n1. Train Timings")
    print("2. Book Ticket")
    print("3. Fare Enquiry")
    print("4. Seat Availability")
    print("5. Exit")

    choice = input("Enter choice: ")

    if choice == "1":
        print("Train arrives at 10:30 AM")

    elif choice == "2":
        print("Ticket booked successfully")

    elif choice == "3":
        print("Fare = Rs.450")

    elif choice == "4":
        print("Seats Available: 32")

    elif choice == "5":
        print("Chatbot Closed")
        break

    else:
        print("Invalid Choice")




# 6.Hill Climbing Algorithm 




import copy

goal = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 0]
]

start = [
    [2, 8, 3],
    [1, 6, 4],
    [7, 0, 5]
]

def heuristic(state):
    count = 0

    for i in range(3):
        for j in range(3):
            if state[i][j] != 0 and state[i][j] != goal[i][j]:
                count += 1

    return count

def find_blank(state):
    for i in range(3):
        for j in range(3):
            if state[i][j] == 0:
                return i, j

def neighbors(state):
    result = []

    x, y = find_blank(state)

    moves = [(-1,0), (1,0), (0,-1), (0,1)]

    for dx, dy in moves:
        nx = x + dx
        ny = y + dy

        if 0 <= nx < 3 and 0 <= ny < 3:
            new_state = copy.deepcopy(state)

            new_state[x][y], new_state[nx][ny] = new_state[nx][ny], new_state[x][y]

            result.append(new_state)

    return result

current = start

while True:
    current_h = heuristic(current)

    best = current
    best_h = current_h

    for state in neighbors(current):
        h = heuristic(state)

        if h < best_h:
            best = state
            best_h = h

    if best_h >= current_h:
        break

    current = best

print("Final State:")

for row in current:
    print(row)

print("Heuristic Value:", heuristic(current))




# 7.Dijkstra Algorithm 





import heapq

graph = {
    'A': [('B', 1), ('C', 4)],
    'B': [('D', 2)],
    'C': [('D', 1)],
    'D': []
}

pq = [(0, 'A')]

distance = {
    'A': 0
}

while pq:
    cost, node = heapq.heappop(pq)

    for neighbor, weight in graph[node]:
        new_cost = cost + weight

        if neighbor not in distance or new_cost < distance[neighbor]:
            distance[neighbor] = new_cost
            heapq.heappush(pq, (new_cost, neighbor))

print("Shortest Distances:")
print(distance)




# 8.Dijkstra on 2D




import heapq

grid = [
    [1, 1, 1],
    [9, 1, 9],
    [1, 1, 1]
]

rows = len(grid)
cols = len(grid[0])

pq = [(0, 0, 0)]

visited = set()

while pq:
    cost, x, y = heapq.heappop(pq)

    if (x, y) in visited:
        continue

    visited.add((x, y))

    if x == rows - 1 and y == cols - 1:
        print("Shortest Cost:", cost)
        break

    moves = [(1,0), (-1,0), (0,1), (0,-1)]

    for dx, dy in moves:
        nx = x + dx
        ny = y + dy

        if 0 <= nx < rows and 0 <= ny < cols:
            heapq.heappush(
                pq,
                (cost + grid[nx][ny], nx, ny)
            )




# 9.N queens using Bactracking




def safe(board, row, col, n):

    for i in range(row):
        if board[i][col] == 1:
            return False

    i = row - 1
    j = col - 1

    while i >= 0 and j >= 0:
        if board[i][j] == 1:
            return False

        i -= 1
        j -= 1

    i = row - 1
    j = col + 1

    while i >= 0 and j < n:
        if board[i][j] == 1:
            return False

        i -= 1
        j += 1

    return True

def solve(board, row, n):

    if row == n:
        for r in board:
            print(r)

        print()
        return

    for col in range(n):

        if safe(board, row, col, n):

            board[row][col] = 1

            solve(board, row + 1, n)

            board[row][col] = 0

n = 4

board = [[0] * n for _ in range(n)]

solve(board, 0, n)





# 10.N queen using Branch and Bound 





def safe(board, row, col, n):

    for i in range(row):
        if board[i][col] == 1:
            return False

    i = row - 1
    j = col - 1

    while i >= 0 and j >= 0:
        if board[i][j] == 1:
            return False

        i -= 1
        j -= 1

    i = row - 1
    j = col + 1

    while i >= 0 and j < n:
        if board[i][j] == 1:
            return False

        i -= 1
        j += 1

    return True

def solve(board, row, n):

    if row == n:
        for r in board:
            print(r)

        print()
        return

    for col in range(n):

        if safe(board, row, col, n):

            board[row][col] = 1

            solve(board, row + 1, n)

            board[row][col] = 0

n = 4

board = [[0] * n for _ in range(n)]

solve(board, 0, n)




# 11.Job Scheduling Problem



def job_scheduling(jobs):

    jobs.sort(key=lambda x: x[2], reverse=True)

    max_deadline = max(job[1] for job in jobs)

    slots = [None] * max_deadline

    total_profit = 0

    for job in jobs:

        job_id, deadline, profit = job

        for i in range(deadline - 1, -1, -1):

            if slots[i] is None:

                slots[i] = job_id
                total_profit += profit

                break

    print("Slots:", slots)
    print("Total Profit:", total_profit)

jobs = [
    ("J1", 1, 3),
    ("J2", 3, 5),
    ("J3", 4, 20),
    ("J4", 3, 18),
    ("J5", 2, 6),
    ("J6", 1, 30),
    ("J7", 2, 30)
]

job_scheduling(jobs)



# 12.Alpha Beta Pruning 



MIN = -1000
MAX = 1000

def minimax(depth, node, maximize, values, alpha, beta):

    if depth == 3:
        return values[node]

    if maximize:

        best = MIN

        for i in range(2):

            value = minimax(
                depth + 1,
                node * 2 + i,
                False,
                values,
                alpha,
                beta
            )

            best = max(best, value)

            alpha = max(alpha, best)

            if beta <= alpha:
                break

        return best

    else:

        best = MAX

        for i in range(2):

            value = minimax(
                depth + 1,
                node * 2 + i,
                True,
                values,
                alpha,
                beta
            )

            best = min(best, value)

            beta = min(beta, best)

            if beta <= alpha:
                break

        return best

values = [2, 3, 5, 9, 0, 1, 7, 5]

result = minimax(0, 0, True, values, MIN, MAX)

print("Optimal Value:", result)



# 13.Sudoku Solver




def print_board(board):

    for row in board:
        print(row)

def empty_position(board):

    for i in range(9):
        for j in range(9):

            if board[i][j] == 0:
                return i, j

    return None

def valid(board, num, pos):

    row, col = pos

    for j in range(9):

        if board[row][j] == num and j != col:
            return False

    for i in range(9):

        if board[i][col] == num and i != row:
            return False

    box_x = col // 3
    box_y = row // 3

    for i in range(box_y * 3, box_y * 3 + 3):
        for j in range(box_x * 3, box_x * 3 + 3):

            if board[i][j] == num and (i, j) != pos:
                return False

    return True

def solve(board):

    position = empty_position(board)

    if not position:
        return True

    row, col = position

    for num in range(1, 10):

        if valid(board, num, (row, col)):

            board[row][col] = num

            if solve(board):
                return True

            board[row][col] = 0

    return False

board = [
    [5,3,0,0,7,0,0,0,0],
    [6,0,0,1,9,5,0,0,0],
    [0,9,8,0,0,0,0,6,0],
    [8,0,0,0,6,0,0,0,3],
    [4,0,0,8,0,3,0,0,1],
    [7,0,0,0,2,0,0,0,6],
    [0,6,0,0,0,0,2,8,0],
    [0,0,0,4,1,9,0,0,5],
    [0,0,0,0,8,0,0,7,9]
]

print("Original Sudoku:\n")
print_board(board)

solve(board)

print("\nSolved Sudoku:\n")
print_board(board)