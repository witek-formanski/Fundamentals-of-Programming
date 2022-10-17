# 2022-10-12
#	11:21 - ?
# 2022-10-13
#	16:50 - 17:50
#	21:18 - 22:26
# 2022-10-14
#	9:52 - 10:09

with open('notepad/201.txt', 'r', encoding="utf8") as file:
	data = file.readlines()
# print(data)

# datastrip = []
# for line in data:
# 	datastrip.append(line.strip())
# print(datastrip)

class Person:
	def __init__(self, name, surname, age):
		self.name = name
		self.surname = surname
		self.age = age

people_list = []
for line_number in range(len(data)):
	print(data[line_number])
	person_list = data[line_number].split(' ')
	if len(person_list) != 3:
		print(f'Error in line {line_number}. Inappropriate number of words.')
		# del data[line_number]
		continue
	elif len(person_list) == 3:
		for word_number in range(len(person_list)):
			# test znaków narodowych
			if word_number == 2:
				try:
					person_list[word_number] = int(person_list[word_number])
				except:
					print(f'Error in line {line_number}. Expected age expressed as an integer.')
					# del data[line_number]
					continue
		if isinstance(person_list[2], int) == True:
			people_list.append(person_list)
# print(people_list)

objects_list = []
for man in people_list:
	x = Person(man[0], man[1], man[2])
	objects_list.append(x)
# print(objects_list)

def show(objects_list, string):
	print(string)
	for i, obj in enumerate(objects_list):
		print('line nr:', i, obj.name, obj.surname, obj.age)

show(objects_list, '\nInitially this is what the list looks like: ')

active1 = True
active2 = False
add = False
change = False
remove = False

while active1:
	x = input('\nDo you want to change, add or remove anything? Type "YES" or "NO": ')
	if x == "YES":
		print('ok yes')
		active2 = True
		while active2:
			x = input('Type "CHANGE", "ADD" or "REMOVE" respectively for action you want to perform: ')
			if x == "CHANGE":
				print('ok change')
				line_flag = True
				while line_flag:
					line_number = input('Type number of line which you want to change: ')
					try:
						line_number = int(line_number)
						line_flag = False					
					except:
						print('Inappropriate value.')
				name = input(f'Type name of person you want to add (instead of {objects_list[line_number].name}): ')
				surname = input(f'Type surname of person you want to add (instead of {objects_list[line_number].surname}): ')
				age_flag = True
				while age_flag:
					age = input(f'Type age of person you want to add (instead of {objects_list[line_number].age}): ')
					try:
						age = int(age)
						age_flag = False
					except:
						print('Inappropriate value.')
				x = Person(name, surname, age)
				print(f'Ok, the person: {x.name} {x.surname} {x.age} has been added to the line {line_number}.')
				objects_list[line_number] = x
				active2 = False
			elif x == "ADD":
				print('ok add')
				name = input('Type name of person you want to add: ')
				surname = input('Type surname of person you want to add: ')
				age_flag = True
				while age_flag:
					age = input('Type age of person you want to add: ')
					try:
						age = int(age)
						age_flag = False
					except:
							print('Inappropriate value. Type an integer.')
				x = Person(name, surname, age)
				print(f'Ok, the person: {x.name} {x.surname} {x.age} has been added.')
				objects_list.append(x)
				active2 = False
			elif x == "REMOVE":
				print('ok remove')
				line_number = input('Type number of line which you want to remove: ')
				line_flag = True
				while line_flag:
					try:
						line_number = int(line_number)
						line_flag = False
					except:
						print('Inappropriate value.')
				print(f'Ok, the person: {objects_list[line_number].name} '\
					f'{objects_list[line_number].surname} {objects_list[line_number].age} has been removed.')
				del objects_list[line_number]
				active2 = False
			else:
				print("I don't understand, please answer again.")
	elif x == "NO":
		print('ok no')
		active1 = False
	else:
		print("I don't understand, please answer again.")

show(objects_list, '\nEventually, that is the final list:')

filename = input('\nName the file: ')
filename_txt = filename+'.txt'
with open(filename_txt, 'w') as f:
	for person in objects_list:
		# line = ' '.join([])
		f.write(f'{person.name} {person.surname} {person.age}\n')
print('Your file has been successfully created.')

input()