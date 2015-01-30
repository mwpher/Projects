#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
File: Students.py
Author: Matthew Pherigo
Email: hybrid120@gmail.com
Github: github.com/mwpher
Description: Manage a table of students and save it as a YAML file
TODO:
- Make backup of file at start of session, then write with every change.
"""

from os import stat 
import pprint
import shutil
import sys
import yaml
from clint.textui import prompt, puts, colored, validators, indent

students = None

def main():
  global students
  with open('Students.yml', 'r') as f:
    if stat("Students.yml").st_size > 0:
      students = yaml.load(f.read())
    else:
      students = {}

  PrintTable()

  while True:
    answer = prompt.query("What would you like to do? (A)dd a student, (r)emove a student, (p)rint the table, or (q)uit?")
    if answer in ['a', 'r', 'p', 'q']:
      if answer == 'a':
        AddStudent()
      if answer == 'q':
        shutil.copy2('Students.yml', 'Students.yml.bak')
        with open('Students.yml', 'w') as f:
          f.write(yaml.dump(students))
        break
      if answer == 'p':
        PrintTable()
      if answer == 'r':
        RemoveStudent()

def PrintTable():
  global students
  puts("Students table thus far:")
  puts(str(pprint.pformat(students, indent=4)))

def AddStudent():
  global students
  name = prompt.query("Enter the student's name")
  pin = prompt.query("Enter their PIN", validators=[validators.IntegerValidator()])
  year = prompt.query("Enter what year of school they are in", validators=[validators.IntegerValidator()])
  students[pin] = {'name': name, 'year': year}
  student_string = '{}: {}'.format(pin, students[pin])
  puts("New student is:")
  with indent(4):
    puts(student_string)
 
def RemoveStudent():
  global students
  pin = prompt.query("Which student should we remove? (PIN): ", validators=[validators.IntegerValidator()])
  puts("You picked:\n{}: {}".format(pin, students[pin]))
  prompt.yn("Remove {}?".format(students[pin]['name']))
  students.pop(pin, None)

if __name__ == '__main__':
  main()
