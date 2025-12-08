from collections import Counter

logfile = "E:\\project 1\\test coding\\js_modules\\access.log"

outputfile = "E:\\project 1\\test coding\\js_modules\\output.txt"

with open(logfile, 'r') as f:
    ips = [line.split()[0] for line in f]

most_common_ip = Counter(ips).most_common(1)[0][0]

with open(outputfile, 'w') as f:
    f.write(most_common_ip)



