import pygame
import food
import player
import AI
import gl

class Game_Window(object):
   def __init__(self):
      pygame.init()

      self.screen = pygame.display.set_mode((400, 400), 0, 32)
      self.clock = pygame.time.Clock()
      # self.player = player.Snake(400,400)
      gl.snake_list = []
      
      for i in range(2):
         name='s'+str(i)
         objname='player'+str(i)
         #self.player=AI.AI(i,i,name)
         #gl.snake_list.append(self.player)
         gl.snake_list.append(AI.AI(i*3,i*3,name))
         
      
      self.Food = food.Food()

      
      self.font = pygame.font.SysFont('Comic Sans MS', 40)

   def blit_grid(self):
      for x in range(40):
         pygame.draw.aaline(self.screen, (255, 255, 255), (x * 10, 0), (x * 10, 400))
      for y in range(40):
         pygame.draw.aaline(self.screen, (255, 255, 255), (0, y * 10), (400, y * 10))

   def game_over(self):
      running = True
      time = 0
      while running :
         time += self.clock.tick()
         for event in pygame.event.get():
            if event.type == pygame.QUIT:
               exit()
            if event.type == pygame.KEYDOWN and time > 1500:
               running = False
         self.screen.fill((255, 255, 255))
         text = self.font.render('GAME OVER ', True, (255, 0, 0))
         self.screen.blit(text, (200 - text.get_width() / 2, 200 - text.get_height()))
         for i in gl.snake_list:
            t2 = 'POINT : ' + str(i.point)
#          t2 = 'POINT : ' + str(self.player.point)
         text2 = self.font.render(t2, True, (255, 0, 0))
         self.screen.blit(text2, (200 - text2.get_width() / 2, 200 + text2.get_height()))
         
         pygame.display.update()
      
      for snake in gl.snake_list:
          snake.is_dead = False
          
      # self.player.is_dead = False
      # self.player2.is_dead = False
      self.clock.tick()
      for snake in gl.snake_list:
          snake.restart()
      # self.player.restart()
      # self.player2.restart()
      self.Food.restart()

   def run(self):
      while True :
         for event in pygame.event.get():
            if event.type == pygame.QUIT:
               exit()
         self.screen.fill((255, 255, 255))

         dt = self.clock.tick()
         #print("DEBUG:dt="+str(dt))
         for snake in gl.snake_list:
             snake.update(dt, self.screen)
             self.Food.update(dt, self.screen, snake)
         
         # self.player.update(dt,self.screen)
         # self.Food.update(dt,self.screen,self.player)
         # self.player2.update(dt,self.screen)
         # self.Food.update(dt,self.screen,self.player2)
         
         self.blit_grid()

         for snake in gl.snake_list:
            if snake.is_dead:
               print 'DEAD:' + snake.name + 'IN:' + str(snake.x) + ' ' + str(snake.y)
               self.game_over()
               

         for snake in gl.snake_list:
            point = self.font.render(str(snake.point), True, (0, 0, 0))
         self.screen.blit(point, (0, 0))
         pygame.display.update()


if __name__ == '__main__':
   app = Game_Window()
   app.run()

