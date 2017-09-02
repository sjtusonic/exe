import pygame
import random
import player
import gl


#     ->x
# |
# V
# y

class AI (player.Snake):
   def __init__(self, x, y,name):
      print 'init AI'
      player.Snake.__init__(self, x, y,name)
      
   def update_position(self, dt):
      print str(self.x) + ',' + str(self.y)
      self.time += dt
      
#       disturb_ratio=0.999
      disturb_ratio=2
      if self.check_dangerous_down() == 0 and self.h_y != 1:
         if random.random() > disturb_ratio:
            self.turn_down()
      if self.check_dangerous_up() == 0 and self.h_y != -1:
         if random.random() > disturb_ratio:
            self.turn_up()
      if self.check_dangerous_left() == 0 and self.h_x != -1:
         if random.random() > disturb_ratio:
            self.turn_left()
      if self.check_dangerous_right() == 0 and self.h_x != 1:
         if random.random() > disturb_ratio:
            self.turn_right()
         
         
      self.check_loop()
      
      if self.h_x == 1 and self.check_dangerous_right():
         if self.check_dangerous_up():
            self.turn_down()
         elif self.check_dangerous_down():
            self.turn_up()
         else:
            self.turn_up_down()
               
      if self.h_x == -1 and self.check_dangerous_left():
         if self.check_dangerous_up():
            self.turn_down()
         elif self.check_dangerous_down():
            self.turn_up()
         else:
            self.turn_up_down()      
               
      if self.h_y == 1 and self.check_dangerous_down():
         if self.check_dangerous_left():
            self.turn_right()
         elif self.check_dangerous_right():
            self.turn_left()
         else:
            self.turn_left_right()
            
      if self.h_y == -1 and self.check_dangerous_up():
         if self.check_dangerous_left():
            self.turn_right()
         elif self.check_dangerous_right():
            self.turn_left()
         else:
            self.turn_left_right()
            
      
      key_pressed = pygame.key.get_pressed()
      if key_pressed[pygame.K_UP] and self.h_y != +1 :
         self.h_x = 0 
         self.h_y = -1
      elif key_pressed[pygame.K_DOWN] and self.h_y != -1 :
         self.h_x = 0
         self.h_y = +1
      elif key_pressed[pygame.K_LEFT] and self.h_x != +1:
         self.h_x = -1
         self.h_y = 0
      elif key_pressed[pygame.K_RIGHT] and self.h_x != -1:
         self.h_x = +1
         self.h_y = 0
      if self.time >= self.time_tick :
         self.tail.insert(0, player.Snake_part((self.x, self.y)))
         self.x += self.h_x
         self.y += self.h_y
         self.head.x, self.head.y = self.x * 10, self.y * 10
         if len(self.tail) > self.length :
            self.tail.pop(len(self.tail) - 1)
         self.time = 0
         
   def update(self, dt, screen):
      self.update_position(dt)
      self.blit(screen)
      self.check_dead()
      print 'x:'+str(self.x)+'y:'+str(self.y)
      
   def check_dead(self):
      for t in self.tail :
         if t.m_x == self.x and t.m_y == self.y :
            self.is_dead = True
            print 'DEAD REASON: hit my self'
      if self.x < 0 or self.x > 40 or self.y < 0 or self.y > 40 :
         self.is_dead = True
         print 'DEAD REASON: run out of field'
      # print gl.snake_list
      for snake in gl.snake_list:
         if self is snake:
            continue
         if snake.x == self.x and snake.y==self.y:
            self.is_dead= True
            print 'DEAD REASON:'+self.name+'head hit '+snake.name+' head!'
         for t in snake.tail:
            if t.m_x == self.x and t.m_y == self.y:
               self.is_dead = True
               print 'DEAD REASON:'+self.name+'head hit'+snake.name+'tail!'
               
   def turn_up_down(self):
      if random.randint(0, 1):
         self.turn_down()
      else:
         self.turn_up()
         
   def turn_left_right(self):
      if random.randint(0, 1):
         self.turn_left()
      else:
         self.turn_right()
         
   def turn_up(self):
      self.h_x = 0 
      self.h_y = -1
   def turn_down(self):
      self.h_x = 0
      self.h_y = +1
   def turn_left(self):
      self.h_x = -1
      self.h_y = 0
   def turn_right(self):
      self.h_x = +1
      self.h_y = 0
         
   def check_dangerous_down(self):
      if self.y == 39:
         return 1
      for t in self.tail :
         if t.m_x == self.x:
            if t.m_y == self.y + 1:
               print 'dangerous down'+self.name
               return 1
      for snake in gl.snake_list:
         if self is snake:
            continue
         if snake.x == self.x and snake.y==self.y+1:
            print 'dangerous down'+self.name
            return 1
            
         for t in snake.tail:
            if t.m_x == self.x:
               if t.m_y == self.y + 1:
                  print 'dangerous down'+self.name
                  return 1
               
      return 0
   def check_dangerous_up(self):
      if self.y == 0:
         return 1
      for t in self.tail :
         if t.m_x == self.x:
            if t.m_y == self.y - 1:
               print 'dangerous up'+self.name
               return 1
      for snake in gl.snake_list:
         if self is snake:
            continue
         if snake.x == self.x and snake.y==self.y-1:
            print 'dangerous up'+self.name
            return 1
         for t in snake.tail:
            if t.m_x == self.x:
               if t.m_y == self.y - 1:
                  print 'dangerous up'+self.name
                  return 1
      return 0
   def check_dangerous_right(self):
      if self.x == 39:
         return 1
      for t in self.tail :
         if t.m_y == self.y:
            if t.m_x == self.x + 1:
               print 'dangerous right'+self.name
               return 1
      for snake in gl.snake_list:
         if self is snake:
            continue
         if snake.x == self.x+1 and snake.y==self.y:
            print 'dangerous right'+self.name
            return 1
         for t in snake.tail:
            if t.m_y == self.y:
               if t.m_x == self.x + 1:
                  print 'dangerous right'+self.name
                  return 1
      return 0
   def check_dangerous_left(self):
      if self.x == 0:
         return 1
      for t in self.tail :
         if t.m_y == self.y:
            if t.m_x == self.x - 1:
               print 'dangerous left'+self.name
               return 1
      for snake in gl.snake_list:
         if self is snake:
            continue
         if snake.x == self.x-1 and snake.y==self.y:
            print 'dangerous left'+self.name
            return 1
         for t in snake.tail:
            if t.m_y == self.y:
               if t.m_x == self.x - 1:
                  print 'dangerous left'+self.name
                  return 1
      return 0

   def check_loop (self): # check if self loop in a close area
      print 'Info:'+self.name+' check loop!'
      largest_cnt=-1
      cnt =2
      for t in self.tail[2:-1]:
         if abs(t.m_x-self.x)<=1 and abs(t.m_y-self.y)<=1:
            print self.name+'hit his tail:'+str(cnt)
            largest_cnt=cnt
         cnt+=1
      
               #zjc
      
      if largest_cnt!=-1:
         inp=largest_cnt
         outp=largest_cnt+1
         print 'judge'+str(inp)+'and'+str(outp)+'!'
         self.h_x=self.tail[outp].m_x-self.tail[inp].m_x
         self.h_y=self.tail[outp].m_y-self.tail[inp].m_y
         print 'set direction to:'+str(self.h_x)+' '+str(self.h_y)
         
      