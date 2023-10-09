def get_height():
    while True:
        try:
            height = int(input("Height: "))
            if (height >= 1) and (height <= 8):
                return height
        except ValueError:
            print ("Not an integer")

height = get_height()

hash = 1
while hash <= height:

    space = height - hash

    while space > 0:
        print (" ", end="")
        space -= 1

    for i in range(hash):
        print ("#", end="")

    hash += 1
    print()