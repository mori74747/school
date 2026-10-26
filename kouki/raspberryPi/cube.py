import numpy as np
import cv2
import math

# ３次元データ(既に計算済みデータ)
# cube = [
#     [-77.4519,-18.3013,-34.1506],
#     [-34.1506,-68.3013,40.8494],
#     [52.4519,-68.3013,-9.1506],
#     [9.1506,-18.3013,-84.1506],
#     [-52.4519,68.3013,9.1506],
#     [-9.1506,18.3013,84.1506],
#     [77.4519,18.3013,34.1506],
#     [34.1506,68.3013,-40.8494]
# ]

# 3次元データ
cube = [
    [0,0,0],
    [0,0,100],
    [100,0,100],
    [100,0,0],
    [0,100,0],
    [0,100,100],
    [100,100,100],
    [100,100,0]
]

# 各頂点の繋げ方を定義
edge = ((0,1),(1,2),(2,3),(3,0),(0,4),(1,5),(2,6),(3,7),(4,5),(5,6),(6,7),(7,4))

# 3次元データを２次元データに変換する関数
def cast(points, Cx, Cy, d):
    x = points[0]
    y = points[1]
    z = points[2]
    sx = ((x/(z/d+1) + Cx)+0.5)
    sy = (Cy - y/(z/d+1)+0.5)
    
    return int(sx), int(sy)

# x,y,x方向に任意の移動を行う関数
def move(cube, x, y, z):
    for points in cube:
        points[0] += x
        points[1] += y
        points[2] += z

    return

# x軸を中心に任意の度数回転する関数
def rotateX(cube,angle):
    a = math.radians(angle)
    for points in cube:
        y = points[1]
        z = points[2]
        points[1] = y*math.cos(a)-z*math.sin(a)
        points[2] = y*math.sin(a)+z*math.cos(a)

    return

# y軸を中心に任意の度数回転する関数
def rotateY(cube,angle):
    a = math.radians(angle)
    for points in cube:
        x = points[0]
        z = points[2]
        points[0] = x*math.cos(a)+z*math.sin(a)
        points[2] = -x*math.sin(a)+z*math.cos(a)
    
    return

# y軸を中心に任意の度数回転する関数
def rotateZ(cube,angle):
    a = math.radians(angle)
    for points in cube:
        x = points[0]
        y = points[1]
        points[0] = x*math.cos(a)-y*math.sin(a)
        points[1] = x*math.sin(a)+y*math.cos(a)
    
    return

# 空白のウィンドウを作成
img = np.zeros((200,200,3), np.uint8)

# 各変数の初期化
Cx = 100
Cy = 100
d = 1000
point = []

# 回転と移動
move(cube,-50,-50,-50)
rotateX(cube,30)
rotateY(cube,30)
rotateZ(cube, 0)

# 三次元データを二次元に変換
for i in range(8):
    point.append(cast(cube[i],Cx,Cy,d))

# 二次元データを描画
for a,b in edge:
    cv2.line(img,point[a],point[b],(255,0,255))

# ウィンドウの表示
cv2.imshow('img',img)
cv2.waitKey(0)
cv2.destroyAllWindows()
