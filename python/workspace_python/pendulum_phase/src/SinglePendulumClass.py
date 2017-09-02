# _*_ coding:utf-8 _*_
'''
Created on 2015年8月9日

@author: admin
'''
import pygame
import random
import gl
import math
      
class SinglePendulumClass (object):
   def __init__(self, pos,freq,A,phi,name,time_tick,direction, color=(0, 255, 0)):
      print('INIT:'+str(name)+'pos='+str(pos)+'freq='+str(freq)+'A='+str(A)+'') 
      self.m_x = pos[0]
      self.m_y = pos[1]
      self.x = self.m_x * 10
      self.old_x=self.m_x
      self.old_y=self.m_y
      self.y = self.m_y * 10
      self.color = color
      self.name=name
      self.freq=freq
      self.A=A
      self.phi=phi
      self.direction=direction

      self.length = 10

      self.tail = []
      #self.time_tick = 100 ;
      self.time_tick = time_tick ;
      self.speed = gl.INIT_SPEED
      self.time = 0
      self.last_key = None
      self.is_dead=False
      self.point = 0

   def blit(self, screen):
      rect = pygame.Rect(self.x, self.y, 10, 10)
      pygame.draw.rect(screen, self.color, rect)

   def update_position(self, dt,screen):
      self.time += dt
      
      if self.direction=='x':
         self.y=self.y
         self.x=self.old_x+self.A*math.cos(2*math.pi*self.freq*self.time+self.phi)
      else:
         self.x=self.x
         self.y=self.old_y+self.A*math.cos(2*math.pi*self.freq*self.time+self.phi)
      
      #print 't='+str(self.time)+'; update:' + self.name + ' IN: ' + str(self.x) + ' ' + str(self.y)
      #print("%s;%s;%s;%s;%s;%s"%(self.name,self.A,self.freq,self.phi,self.time,self.direction))
      self.blit(screen)
      if self.time >= self.time_tick :
         #self.x += self.h_x
         #self.y += self.h_y
         #self.head.x, self.head.y = self.x * 10, self.y * 10
         self.time = 0
         
   def update(self,dt,screen):
      self.update_position(dt,screen)
   def get_loc(self):
      return (self.x,self.y)