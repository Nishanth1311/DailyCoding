#dc 1104

# Keypads from old phones
keypad =  {'2': ['a', 'b', 'c'], '3': ['d', 'e', 'f'], '4': ['g', 'h', 'i'], '5': ['j,' 'k', 'l'], '6': ['m', 'n', 'o'], '7': ['p', 'q', 'r', 's'], '8': ['t', 'u', 'v'], '9': ['w', 'x', 'y', 'z']}

# input
num = input()

# Set the current_list to the first number
current_list = keypad[num[0]]

# Iterate over to get a result of all possible combinations
for i in range(1, len(num)):
    new_list = []
    for j in range(len(current_list)):
        for alphabet in keypad[num[i]]:
            new_list.append(str(current_list[j] + alphabet))
    current_list = new_list

print(current_list)
