def pyramid(height):
    for i in range(1, height + 1):
        spaces = height - i
        sharps = i
        print(" " * spaces + "#" * sharps)

# Pede a altura
height = int(input("Height: "))

while height < 1 or height > 8:
    height = int(input("Height: "))

pyramid(height)