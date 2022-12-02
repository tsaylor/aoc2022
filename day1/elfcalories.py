# part 1

elves = []
with open("input.txt") as infile:
    data = infile.readlines()
cur_elf = []
for line in data:
    if line == '\n':
        elves.append(cur_elf)
        cur_elf = []
    else:
        cur_elf.append(int(line))
print(max([sum(elf) for elf in elves]))

# part 2

annotated_elves = []
for elf in elves:
    annotated_elves.append((sum(elf), elf))

annotated_elves = sorted(annotated_elves, key=lambda x: x[0], reverse=True)

from pprint import pprint as pp
pp(annotated_elves[:3], width=160)

print(sum([ae[0] for ae in annotated_elves[:3]]))

