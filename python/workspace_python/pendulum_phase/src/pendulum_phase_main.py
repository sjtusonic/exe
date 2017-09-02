# _*_ coding:utf-8 _*_
"""
Created on 2015年8月9日

@author: admin
"""
import pygame
import SinglePendulumClass
import gl
import math
 

class GameWindow(object):
    def __init__(self):
        pygame.init()

        self.screen = pygame.display.set_mode((800, 800), 0, 32)
        self.clock = pygame.time.Clock()
        # self.player = player.Snake(400,400)
        gl.pendulum_list = []
        self.COUNT = 80
        for i in range(self.COUNT):
            name = 's' + str(i)
            #objname = 'player' + str(i)
            # self.player=AI.AI(i,i,name)
            #gl.pendulum_list.append(self.player)
            if i < self.COUNT / 2:
                a = 100
                loc = [a, i * 1]

                pos = loc
                freq = 0.0000 * i + 0.001
                phi = i * 1.0 / self.COUNT * 2 * math.pi
                name = name
                time_tick = 100000
                direction = 'x'
                color = gl.COLOR

                gl.pendulum_list.append(
                    SinglePendulumClass.SinglePendulumClass(pos, freq, a, phi, name, time_tick, direction, color))
                #  def __init__(self, pos,freq,a,phi,name,time_tick,direction, color=(0, 255, 0)):
            else:
                a = 100
                loc = [i - self.COUNT / 2, a]

                pos = loc
                freq = 0.0000 * i + 0.001
                phi = i * 1.0 / self.COUNT * 2 * math.pi
                name = name
                time_tick = 100000
                direction = 'y'
                color = gl.COLOR

                gl.pendulum_list.append(
                    SinglePendulumClass.SinglePendulumClass(pos, freq, a, phi, name, time_tick, direction, color))

        self.font = pygame.font.SysFont('Comic Sans MS', 40)

    def blit_grid(self):
        for x in range(40):
            pygame.draw.aaline(self.screen, (255, 255, 255), (x * 10, 0), (x * 10, 400))
        for y in range(40):
            pygame.draw.aaline(self.screen, (255, 255, 255), (0, y * 10), (400, y * 10))

    def game_over(self):
        running = True
        time = 0
        while running:
            time += self.clock.tick()
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    exit()
                if event.type == pygame.KEYDOWN and time > 1500:
                    running = False
            self.screen.fill((255, 255, 255))
            text = self.font.render('GAME OVER ', True, (255, 0, 0))
            self.screen.blit(text, (200 - text.get_width() / 2, 200 - text.get_height()))
            for i in gl.pendulum_list:
                t2 = 'POINT : ' + str(i.point)
            # t2 = 'POINT : ' + str(self.player.point)
            text2 = self.font.render(t2, True, (255, 0, 0))
            self.screen.blit(text2, (200 - text2.get_width() / 2, 200 + text2.get_height()))

            pygame.display.update()

        for snake in gl.pendulum_list:
            snake.is_dead = False

        # self.player.is_dead = False
        # self.player2.is_dead = False
        self.clock.tick()
        for snake in gl.pendulum_list:
            snake.restart()
        # self.player.restart()
        # self.player2.restart()
        self.Food.restart()

    def run(self):
        while True:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    exit()
            self.screen.fill((255, 255, 255))

            dt = self.clock.tick()
            # print("DEBUG:dt="+str(dt))
            for snake in gl.pendulum_list[0:self.COUNT / 2 - 1]:
                a_loc = snake.get_loc()
                ax = a_loc[0]
                ay = a_loc[1]
                for node in gl.pendulum_list[self.COUNT / 2:]:
                    #print ('iteration:%s'%node.name)
                    b_loc = node.get_loc()
                    bx = b_loc[0]
                    by = b_loc[1]
                    #print('a_loc=%s;b_loc=%s'%(a_loc,b_loc))
                    #if a_loc==b_loc:
                    if abs(ax - bx) + abs(ay - by) < 10:
                        #print('a_loc=%s;b_loc=%s'%(a_loc,b_loc))
                        node.color = (255, 0, 0)

            for snake in gl.pendulum_list:
                snake.update(dt, self.screen)

            for snake in gl.pendulum_list:
                snake.color = gl.COLOR
                #self.Food.update(dt, self.screen, snake)

            # self.player.update(dt,self.screen)
            # self.Food.update(dt,self.screen,self.player)
            # self.player2.update(dt,self.screen)
            # self.Food.update(dt,self.screen,self.player2)

            self.blit_grid()

            for snake in gl.pendulum_list:
                if snake.is_dead:
                    print 'DEAD:' + snake.name + 'IN:' + str(snake.x) + ' ' + str(snake.y)
                    self.game_over()

            for snake in gl.pendulum_list:
                point = self.font.render(str(snake.point), True, (0, 0, 0))
            self.screen.blit(point, (0, 0))
            pygame.display.update()


if __name__ == '__main__':
    app = GameWindow()
    app.run()
