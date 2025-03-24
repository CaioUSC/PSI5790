import cv2
import numpy as np

def mediana(a):
    b = np.zeros_like(a)
    rows, cols = a.shape
    for l in range(rows):
        for c in range(cols):
            v = []
            for l2 in range(-1, 2):
                for c2 in range(-1, 2):
                    l3 = l + l2
                    c3 = c + c2
                    
                    if l3 < 0:
                        l3 = -l3
                    if l3 >= rows:
                        l3 = rows - (l3 - rows + 2)
                    if c3 < 0:
                        c3 = -c3
                    if c3 >= cols:
                        c3 = cols - (c3 - cols + 2)

                    v.append(a[l3, c3])

            # Encontrando o valor mediano
            v.sort()
            mid = len(v) // 2
            b[l, c] = v[mid]
    
    return b

# Carregar a imagem
a = cv2.imread("ruido.png", cv2.IMREAD_GRAYSCALE)

# Aplicar o filtro de mediana
b = mediana(a)

# Salvar a imagem resultante
cv2.imwrite("mediana_ruido.png", b)