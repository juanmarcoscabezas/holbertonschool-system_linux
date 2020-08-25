#!/usr/bin/python3

import threading

def setInterval(func,time):
    e = threading.Event()
    while not e.wait(time):
        func()

def foo():
    print("hello")

while True:
    setInterval(foo, 2)