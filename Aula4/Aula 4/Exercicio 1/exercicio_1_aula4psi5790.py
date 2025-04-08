#dtree.py - grad2023
import numpy as np
from sklearn import tree
import sys
import cv2

#<<<<<<<<<<<<<<< main <<<<<<<<<<<<<<<<<
ax=cv2.imread("janei.png",1)
ay=cv2.imread("janei-1.png",0)
if ax.shape[0]!=ay.shape[0] or ax.shape[1]!=ay.shape[1]:
  sys.exit("Erro: Imagens com dimensoes diferentes");

features=(ax/255).reshape((ax.shape[0]*ax.shape[1],3))
saidas  =(ay/255).reshape((ay.shape[0]*ay.shape[1],))


arvore= tree.DecisionTreeClassifier(class_weight="balanced")
arvore= arvore.fit(features, saidas)

qx=cv2.imread("julho.png",1)
query=(qx/255).reshape((qx.shape[0]*qx.shape[1],3))

qp=arvore.predict(query)
qp=qp.reshape((qx.shape[0],qx.shape[1]))
cv2.imwrite("julho-dt-py.png",255 * qp)
# Carregar a imagem em escala de cinza
a = cv2.imread("julho-dt-py.png",0)
a



# Filtro para destacar apenas a parte mais densa da imagem
# Criar uma imagem b com o mesmo tamanho de a
b = np.zeros_like(a, dtype=np.uint8)

a = a / 255

# Iterar sobre os pixels da imagem (exceto as bordas)
for l in range(2, a.shape[0] - 2):
    for c in range(2, a.shape[1] - 2):
        # Soma dos 25 vizinhos do pixel (incluindo o próprio pixel)
        soma = np.sum(a[l-2:l+3, c-2:c+3])  #

        # Média dos valores
        mean = soma / 25

        # Se a média for maior ou igual a 0.05, o pixel é 255 (branco), senão é 0 (preto)
        if mean >= 0.05:
            b[l, c] = 255
        else:
            b[l, c] = 0
# Salvar a imagem processada
cv2.imwrite("eliminaruibrpr.bmp", b)
b

median = cv2.medianBlur(b,7)
cv2.imwrite("filtromediana.bmp", median)
median

# Sobreposição de imagens
imagem1 = cv2.imread('julho.png')
imagem2 = cv2.imread('filtromediana.bmp')

# Verificar se as imagens têm o mesmo tamanho, se necessário, redimensione uma delas
if imagem1.shape != imagem2.shape:
    imagem2 = cv2.resize(imagem2, (imagem1.shape[1], imagem1.shape[0]))

sobreposicao = np.where(imagem2 != 0, imagem2, imagem1)  # Imagem1 será a base e imagem2 sobreporá onde houver conteúdo

# Criamos uma mascara onde a imagem 2 possui pixels pretos
mascara = np.all(imagem2 == 0, axis=-1)

# Pinta a área de sobreposição de vermelho
imagem_final = imagem1.copy()
imagem_final[mascara] = [255, 0, 0]

cv2.imwrite('imagem_final.jpg', imagem_final)
imagem_final