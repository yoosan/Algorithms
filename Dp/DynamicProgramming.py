def fibonacci(n):
	global numCall
	numCall += 1
	#print("fibonacci call with", n)
	if n <= 1:
		return 1
	else:
		return fibonacci(n-1) + fibonacci(n-2)

def fastfibo(n, memory):
	global numCallf
	numCallf += 1
	#print "fibonacci call with" + n
	if not n in memory:
		memory[n] = fastfibo(n-1, memory) + fastfibo(n-2, memory)
	return memory[n]
def fastfibonacci(n):
	memory = {0:1, 1:1}
	return fastfibo(n, memory)

def dynamicpro(w, v, i, aw):
	if i  == 0:
		if w[i] <= aw:
			return v[i]
		else:
			return 0
	without_i = dynamicpro(w, v, i - 1, aw)
	if w[i] > aw:
		return without_i
	else:
		with_i = v[i] + dynamicpro(w, v, i-1, aw - w[i])
	return max(without_i, with_i)

def fastdp(w, v, i, aw, m):
	try: return m[(i, aw)]
	except KeyError:
		if i == 0:
			if w[i] <= aw:
				m[(i, aw)] = v[i]
				return v[i]
			else:
				m[(i, aw)] = 0
				return 0
		without_i = fastdp(w, v, i-1, aw, m)
		if w[i] > aw:
			m[(i, aw)] = without_i
			return without_i
		else:
			with_i = v[i] + fastdp(w, v, i-1, aw - w[i], m)
		res = max(with_i, without_i)
		m[(i, aw)] = res
		return res
def fastdynpro(w, v, i, aw):
	m = {}
	return fastdp(w, v, i, aw, m)




weight = [1, 5, 3, 4]
value = [15, 10, 9, 5] 
optimal = dynamic       pro(weight, value, len(value)-1, 8)
fastoptimal = fastdynpro(weight, value, len(value)-1, 8)

print optimal
print fastoptimal
