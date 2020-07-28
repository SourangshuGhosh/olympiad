# Ivan Carvalho
# Solution to https://www.urionlinejudge.com.br/judge/problems/view/1190
#!/usr/bin/env python2.7
# encoding : utf-8
array = [[0 for j in xrange(12)] for k in xrange(12)]
operacao = raw_input()
count = 0
for p in xrange(12):
	for k in xrange(12):
		e = float(raw_input())
		if p + k >= 12 and p < k:
			array[p][k] = e
			count += 1
if operacao == "S":
	print "%.1f" % (sum([sum(x) for x in array]))
else:
	print "%.1f" % (sum([sum(x) for x in array])/float(count))
