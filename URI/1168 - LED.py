led = [6, 2, 5, 5, 4, 5, 6, 3, 7, 6]
n = int(input())

for i in range(0, n):
  str = input()
  sum = 0
  for ch in str:
    sum += led[int(ch)]
  print("{} leds".format(sum))