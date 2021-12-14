import csv
f = open('zcomock1_ranklist.csv', 'r')
fread = csv.reader(f)

newrows = []
columns = ['CF Handle', 'Total', 'A', 'B']
for row in fread:
	if row[0] == 'Timestamp':
		continue
	#print(row)
	r = []
	r.append(row[1])
	a_score = 0
	for i in range(3, 9):
		if row[i] == '':
			continue
		a_score += int(row[i])
	b_score = 0
	for i in range(9, 17):
		if row[i] == '':
			continue
		b_score += int(row[i])
	r += [a_score + b_score, a_score, b_score]
	print(r)
	newrows.append(r)

f.close()
newf = open('final_ranks.csv', 'w')
writer = csv.writer(newf)
writer.writerow(columns)
writer.writerows(newrows)
newf.close()