import csv
import sys
import subprocess
import os
from statistics import stdev, mean

def main():
	if len(sys.argv) != 3:
		print('Usage: <filename> <testcase>')
		sys.exit(-1)
	
	filename = sys.argv[1]
	testcase = sys.argv[2]

	testcases = {
		'multiple_points': [1000, 10, 3],
		'multiple_dim': [100, 50000, 3],
		'common': [1000, 1000, 3]
	}

	iterations = 3
	cores = [1, 2, 4, 8, 12, 16, 24]

	def run(testcase, cores):
		wall_time = []
		sys_time = []
		
		for it in range(iterations):
			p = subprocess.Popen(['time', '-f%e_%U_%S', './benchmark'] + [str(p) for p in testcases[testcase]] + [str(cores)], stderr=subprocess.PIPE, stdout=subprocess.PIPE)
			out, err = p.communicate()
			t = err.split(b'_')
			wt = t[0]
			st = t[2]
			wall_time.append(float(wt))
			sys_time.append(float(st))
		return mean(wall_time), stdev(wall_time), mean(sys_time), stdev(sys_time)

	with open(testcase + "_" + filename + ".csv", 'w') as csv_file:
		fieldnames = ['num_cores', 'wall_time_avg', 'wall_time_dev', 'sys_time_avg', 'sys_time_dev']
		writer = csv.DictWriter(csv_file, fieldnames=fieldnames)

		writer.writeheader()
		for c in cores:
			print('Measuring', testcase, 'for', c, 'cores')
			wall_time_avg, wall_time_dev, sys_time_avg, sys_time_dev = run(testcase, c)
			writer.writerow({'num_cores': c, 'wall_time_avg': wall_time_avg,  'wall_time_dev': wall_time_dev, 'sys_time_avg': sys_time_avg, 'sys_time_dev': sys_time_dev})

if __name__ == '__main__':
	main()
