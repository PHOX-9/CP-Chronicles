from collections import deque
def bfs(x, y, n, m, a, b):
    q = deque()
    q.append((x, y))
    b[x][y] = 0
    while q:
        u, v = q.popleft()
        if u + 1 < n and b[u + 1][v] == int(1e9 + 7) and a[u + 1][v]:
            b[u + 1][v] = b[u][v] + 1
            q.append((u + 1, v))
        if v + 1 < m and b[u][v + 1] == int(1e9 + 7) and a[u][v + 1]:
            b[u][v + 1] = b[u][v] + 1
            q.append((u, v + 1))
        if u - 1 >= 0 and b[u - 1][v] == int(1e9 + 7) and a[u - 1][v]:
            b[u - 1][v] = b[u][v] + 1
            q.append((u - 1, v))
        if v - 1 >= 0 and b[u][v - 1] == int(1e9 + 7) and a[u][v - 1]:
            b[u][v - 1] = b[u][v] + 1
            q.append((u, v - 1))
def read():
    n, m, k = map(int, input().split())
    a = []
    b = []
    x, y = 0, 0
    for i in range(n):
        row = input().strip()
        a_row = []
        b_row = []
        for j in range(len(row)):
            c = row[j]
            b_row.append(int(1e9 + 7))
            if c == '*':
                a_row.append(0)
            else:
                a_row.append(1)
            if c == 'X':
                x = i
                y = j
        a.append(a_row)
        b.append(b_row)
    return n, m, k, x, y, a, b
def main():
    n, m, k, x, y, a, b = read()
    if (k % 2 == 1 or ((x + 1 >= n or not a[x + 1][y]) and (y + 1 >= m or not a[x][y + 1]) and (x - 1 < 0 or not a[x - 1][y]) and (y - 1 < 0 or not a[x][y - 1]))):
        print("IMPOSSIBLE")
        return
    bfs(x, y, n, m, a, b)
    m_x = x
    m_y = y
    ans = 0
    s = ""
    while ans < k:
        if m_x + 1 < n and a[m_x + 1][m_y] and b[m_x + 1][m_y] + ans <= k:
            m_x += 1
            ans += 1
            s += 'D'
        elif m_y - 1 >= 0 and a[m_x][m_y - 1] and b[m_x][m_y - 1] + ans <= k:
            m_y -= 1
            ans += 1
            s += 'L'
        elif m_y + 1 < m and a[m_x][m_y + 1] and b[m_x][m_y + 1] + ans <= k:
            m_y += 1
            ans += 1
            s += 'R'
        elif m_x - 1 >= 0 and a[m_x - 1][m_y] and b[m_x - 1][m_y] + ans <= k:
            m_x -= 1
            ans += 1
            s += 'U'
    print(s)
if __name__ == "__main__":
    main()
