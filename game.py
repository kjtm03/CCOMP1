import pygame
import os
import sys


ANCHO = 768
LARGO = 480

DIRECCION = "imagenes"

BLANCO = (255, 255, 255)

#-------------------------------------------------------------------


class Pelota(pygame.sprite.Sprite):

    def __init__(self):
        pygame.sprite.Sprite.__init__(self)

        self.image = cargar_img("bola.png", DIRECCION, True)
        self.rect = self.image.get_rect()
        self.rect.centerx = ANCHO/2
        self.rect.centery = LARGO/2
      
        self.speed = [6,6]

    def  refrescar(self):
        global vidas
        global puntajes
        if self.rect.left < 0 or self.rect.right > ANCHO:
            self.speed[0] = -self.speed[0]
        if self.rect.top < 0 :
            self.speed[1] = -self.speed[1]
        if self.rect.bottom > LARGO : 
            self.rect.centerx = ANCHO/2 
            self.rect.centery = LARGO/2
            
            self.vidas[0] -= 1

        self.rect.move_ip((self.speed[0], self.speed[1]))

    def colision(self, objeto):
        if self.rect.colliderect(objeto.rect):
            self.speed[1] = -self.speed[1]

    def draw(self, screen):
        screen.blit(self.image, self.rect)

#-------------------------------------------------------------------

class Barra(pygame.sprite.Sprite):

    def __init__(self, y):
        pygame.sprite.Sprite.__init__(self)

        self.image = cargar_img("paleta.png", DIRECCION, True)
        self.rect = self.image.get_rect()
        self.rect.centerx = 384
        self.rect.centery = 460

    def control(self):
        if self.rect.right >= ANCHO:
            self.rect.right = ANCHO
        elif self.rect.left <= 0:
            self.rect.left = 0

    def draw(self, screen):
        screen.blit(self.image, self.rect)

#-------------------------------------------------------------------

class Bloque(pygame.sprite.Sprite):

    def __init__(self, x, y):
        pygame.sprite.Sprite.__init__(self)

        self.image = cargar_img("ladrillo.png", DIRECCION, True)
        self.rect = self.image.get_rect(x=x, y=y)


def cargar_img(nombre, direccion, alpha=False):

    ruta = os.path.join(direccion, nombre)
    try:
        image = pygame.image.load(ruta)
    except:
        print("Error al cargar la Imagen, compruebe la ruta")
        pygame.quit()
        sys.exit(1)
    if alpha:
        image = image.convert_alpha()
    else:
        image = image.convert()

    return image

#-------------------------------------------------------------------

def juego():
    
    pygame.init()
    gameOver = False
    ganar = False
    restart = False

    pantalla = pygame.display.set_mode ((ANCHO, LARGO))
    pantalla_rect = pantalla.get_rect()

    pygame.display.set_caption("Juego de Progra")


    fondo = cargar_img("fondo.jpg", DIRECCION)

    bola  = Pelota()
    barra = Barra(25)
    ladrillos = pygame.sprite.Group()

    for y in range(6):
        for x in range(15):
            ladrillos.add( Bloque(x*50+7, y*20) )


    vidas = [5] 
    bola.vidas = vidas
    puntajes = [0]
    bola.puntajes = puntajes

    font = pygame.font.Font(None, 40)


    gameOver_texto = font.render("Game Over", True, BLANCO)
    gameOver_texto_rect = gameOver_texto.get_rect(center=pantalla_rect.center)


    ganar_texto = font.render("¡Ganaste!", True, BLANCO)
    ganar_texto_rect = ganar_texto.get_rect(center=pantalla_rect.center)


    pygame.key.set_repeat(1, 20)

    reloj = pygame.time.Clock()

    while gameOver == False and ganar == False:
        reloj.tick(60)

        if vidas[0] <= 0:
            gameOver = True
        if puntajes[0] >= 4000:
            ganar = True
        
        bola.refrescar()
        bola.colision(barra)
        barra.control()
            
        golpe = pygame.sprite.spritecollide(bola, ladrillos, dokill=True)

        if golpe:
            bola.speed[1] = -bola.speed[1]
            puntajes[0] += 50

        vida = font.render(str(vidas[0]), True, BLANCO)
        vida_rect = vida.get_rect(x=10, y=450)

        puntaje = font.render(str(puntajes[0]), True, BLANCO)
        puntaje_rect = puntaje.get_rect(x=700, y=450)
      
        
        pantalla.blit(fondo,(0,0))
        bola.draw(pantalla)
        barra.draw(pantalla)
        ladrillos.draw(pantalla)
        pantalla.blit(vida, vida_rect)
        pantalla.blit(puntaje, puntaje_rect)


        if gameOver == True:
            pantalla.blit(gameOver_texto, gameOver_texto_rect)
            restart = True
            print(restart)
        if ganar == True:
            pantalla.blit(ganar_texto, ganar_texto_rect)

        pygame.display.flip()

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit(0)

            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:
                    barra.rect.x -= 20
                elif event.key == pygame.K_RIGHT:
                    barra.rect.x += 20
                elif event.key == pygame.K_ESCAPE:
                    pygame.quit()
                    sys.exit(0)
                elif event.key == pygame.K_SPACE:
                    juego()

#if restart == True:
    #pygame.init()
    #agregamos luego un event.key para resetear el juego
#-------------------------------------------------------------------                    
juego()
      
