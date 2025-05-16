def knapsack(projects, budget):
    n = len(projects)
    dp = [[0 for _ in range(budget + 1)] for _ in range(n + 1)]

    for i in range(1, n + 1):
        cost, profit = projects[i - 1]
        for w in range(1, budget + 1):
            if cost <= w:
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - cost] + profit)
            else:
                dp[i][w] = dp[i - 1][w]

    # Backtrack to find the selected projects
    selected_projects = []
    w = budget
    for i in range(n, 0, -1):
        if dp[i][w] != dp[i - 1][w]:
            selected_projects.append(i)
            w -= projects[i - 1][0]

    return dp[n][budget], selected_projects

projects = [(3, 4), (4, 5), (7, 10), (8, 11), (9, 13), (6, 7)]
budget = 15
max_profit, selected_projects = knapsack(projects, budget)

print(f"Maximum Profit: ${max_profit * 1000}")
print(f"Selected Projects: {selected_projects}")
