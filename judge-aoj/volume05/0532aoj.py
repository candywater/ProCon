#python3
'''
"Copyright (c) 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010,
  2011, 2012, 2013, 2014 Python Software Foundation; All Rights Reserved"
'''
import sys
while 1:  
  try:
    h1,m1,s1,h2,m2,s2=map(int,input().split())
  except EOFError: break
  '''<- this is /* in c/c++
  m1=input()
  s1=input()
  h2=input()
  m2=input()
  s2=input()
  ''' 

  s1=s2+60-s1  
  s2=s1%60
  s1=s1/60

  m1=m2+60-1-m1+s1
  m2=m1%60
  m1=m1/60

  h2=h2-h1-1+m1

#print("d d d"%(h,m,s)) <- wrong format
  print('%d'%h2,'%d'%m2,'%d'%s2)
