from cs1graphics import*
import time

""" 
This program is prepared by ASTU 2016 batch freshman students as a group project.
we tried to mimic a town described in one of our childhood animation series called "Miraculous world: tales of ladybug and cat noir". in this fictional town 
there are group of teenage frieds having various super powers which they use to defend the town they live in from the villan called "Howk Moth".
and in this program we mantiond theme by making theme part of our program.
at first we progrmed this project by modular programing methode, but we combind theme in to a single program to make our file managemant more efficient.

#### Group name:
1, Menwuyelet Temesgen ........... ugr/34920/16......sec. 46
2, Misgana Tilahun ............... ugr/35008/16......sec. 45
3, Eyosiyas Fisseha .............. ugr/34376/16......sec. 46
4, Taju Tarekegn ................. ugr/35465/16......sec. 46
5, Misgana Tesfaye ............... ugr/35007/16......sec. 46
6, Lidiya Getachew ............... ugr/34823/16......sec. 46
"""

Miraculous_world = Canvas(1300,800)
Miraculous_world.setBackgroundColor("green")
Miraculous_world.setTitle("World of Miraculous")

## this creats clouds
def Cloud(x, y, color):
    cloud = Layer()
    c1 = Circle(20, Point(100, 100)) 
    c1.setFillColor(color)
    c1.setBorderColor(color)
    c2 = Circle(20, Point(100, 115))
    c2.setFillColor(color)
    c2.setBorderColor(color)
    c3 = Circle(10, Point(115, 115))
    c3.setFillColor(color)
    c3.setBorderColor(color)
    c4 = Circle(20, Point(130, 110))
    c4.setFillColor(color)
    c4.setBorderColor(color)
    c5 = Circle(20, Point(130, 100))
    c5.setFillColor(color)
    c5.setBorderColor(color)
    ##
    cloud.add(c1)
    cloud.add(c2)
    cloud.add(c3)
    cloud.add(c4)
    cloud.add(c5)
    ##
    cloud.moveTo(x, y)
    Miraculous_world.add(cloud)
## this creats roads 
def RoadA():
    roadA= Rectangle(1300,60 )
    roadA.setFillColor("black")
    roadA.setBorderColor("black")
    return(roadA)
def RoadB():
    roadB = Layer()
    road = Polygon(Point(750, 260), Point(630, 105), Point(610,105), Point(500, 250))
    road.setFillColor("black")
    line = Polygon(Point(125, 200), Point(117, 180))
    line.setFillColor("white")
    roadB.add(road)
    roadB.setDepth(51)
    return (roadB)

## this crats the sidewalks
def side_walk1():
    road = Polygon(Point(593, 350), Point(528, 450), Point(-100,450), Point(-44, 350))
    road.setFillColor("gray")
    road.setBorderColor("darkgrey")
    return(road)
def side_walk2():
    road =  Polygon(Point(455, 245), Point(1000, 245), Point(1000, 350), Point(550, 350))
    road.setFillColor("darkgray")
    road.setBorderColor("darkgrey")
    return(road)

## this creats fenses 
def Fens1():
    fens = Layer()
    l1 = Rectangle(10,30, Point(650, 400))
    l1.setFillColor("brown")
    l1.setBorderColor("brown")
    fens.add(l1)
    l2 = l1.clone()
    l2.moveTo(670, 400)
    fens.add(l2)
    l3 = l1.clone()
    l3.moveTo(690, 400)
    fens.add(l3)
    l4 = l1.clone()
    l4.moveTo(710, 400)
    fens.add(l4)
    l5 = l1.clone()
    l5.moveTo(730, 400)
    fens.add(l5)
    l6 = l1.clone()
    l6.moveTo(750, 400)
    fens.add(l6)
    l7 = l1.clone()
    l7.moveTo(770, 400)
    fens.add(l7)
    l8 = l1.clone()
    l8.moveTo(790, 400)
    fens.add(l8)
    l9 = l1.clone()
    l9.moveTo(810, 400)
    fens.add(l9)
    l10 = l1.clone()
    l10.moveTo(830, 400)
    fens.add(l10)
    return(fens)
def Fens2():
    fens = Layer()
    l1 = Fens1().clone()
    l2 = Rectangle(10,30, Point(810, 400))
    l2.setFillColor("brown")
    l2.setBorderColor("brown")
    l3 = Rectangle(10,30, Point(830, 400))
    l3.setFillColor("brown")
    l3.setBorderColor("brown")
    fens.add(l1)
    fens.add(l2)
    fens.add(l3)
    fens.moveTo(0,0)
    return(fens)

## this creats the entrance roads
def Entrance1():
    entrance = Polygon(Point(380, 450), Point(350, 405), Point(270, 405), Point(230,450))
    entrance.setFillColor("black")
    entrance.setBorderColor("black")
    return (entrance)
def Entrance2():
    entrance = Polygon(Point(750, 300), Point(750, 270), Point(760, 260), Point(700, 270))
    entrance.setFillColor("white")
    entrance.setBorderColor("black")
    return (entrance)

    ##

## this creats the hotel
def Hotel(x, y):
    hotel= Layer()
    r = Rectangle(200,400, Point(1000, 500))
    r.setFillColor("darkred")
    l1 = Path(Point(890, 575), Point(1110, 575))
    l1.setBorderWidth(10)
    l1.setBorderColor("black")
    l1.setDepth(49)
    l2 = Path(Point(890,300), Point(1110, 300))
    l2.setBorderWidth(5)
    l2.setBorderColor("gold")
   ##dor
    dor = Rectangle(100, 75 , Point(1000, 662.5))
    dor.setFillColor("skyblue")
    dor_l1 = Path(Point(950,645), Point(1050, 645))
    dor_l2 = Path(Point(1000, 645), Point(1000, 700))
    dor_l3 = Path(Point(970,645), Point(970, 700))
    dor_l4 = Path(Point(1030,645), Point(1030, 700))
    dor_l5 = Path(Point(1030,672.5), Point(1030, 672.5))
    dor_l6 = Path(Point(950,672.5), Point(970, 672.5))
    dor_16a =Path(Point(1030,672.5),Point(1050,672.5))
    dor_l7 = Path(Point(1005,677.5), Point(1005,662.5 ))
    dor_l8 = Path(Point(995,677.5), Point(995, 662.5))
    hotel.add(r)
    hotel.add(l1)
    hotel.add(l2)
    hotel.add(dor)
    hotel.add(dor_l1)
    hotel.add(dor_l2)
    hotel.add(dor_l3)
    hotel.add(dor_l4)
    hotel.add(dor_l5)
    hotel.add(dor_l6)
    hotel.add(dor_16a)
    hotel.add(dor_l7)
    hotel.add(dor_l8)
    
    ##Window
    window =Layer()
    wa= Rectangle(30,45 , Point(1000,645))
    wa.setFillColor("lightblue")

    W = Path(Point(985,645),Point(1015,645))
    W.setDepth(49)
    window.add(W)
    window.add(wa)

    win1=window.clone()
    hotel.add(win1)
    win1.move(75,0)

    win2 =window.clone()
    hotel.add(win2)
    win2.move(-75,0)

    win3 =window.clone()
    hotel.add(win3)
    win3.move(50,-125)

    win4 =window.clone()
    hotel.add(win4)
    win4.move(50,-200)

    win5 =window.clone()
    hotel.add(win5)
    win5.move(50,-275)

    win6 =window.clone()
    hotel.add(win6)
    win6.move(5,-125)

    win7 =window.clone()
    hotel.add(win7)
    win7.move(5,-200)

    win8 =window.clone()
    hotel.add(win8)
    win8.move(5,-275)
    ## hotel
    advert= Rectangle(40,180 , Point(1000,645))
    advert.setFillColor("orange")
    advert.setBorderColor("darkred")
    hotel.add(advert)
    advert.move(-65,-265) 
    H=Text("H",20, Point(1000,645))
    H.setFontColor("white")
    O=Text("O",20, Point(1000,645))
    O.setFontColor("white")
    T=Text("T",20, Point(1000,645))
    T.setFontColor("white")
    E=Text("E",20, Point(1000,645))
    E.setFontColor("white")
    L=Text("L",20, Point(1000,645))
    L.setFontColor("white")

    hotel.add(H)
    H.move(-65,-315)

    hotel.add(O)
    O.move(-65,-290)

    hotel.add(T)
    T.move(-65,-265)

    hotel.add(E)
    E.move(-65,-240)

    hotel.add(L)
    L.move(-65,-215)
    ##
    name = Text("Le Grand Paris", 18, Point(1000, 575))
    name.setFontColor("gold")
    hotel.add(name)
    name.setDepth(47)
    
    ## Right bldg
    def right_bldg():
        r = Rectangle(150,300, Point(1000, 500))
        r.move(176,50)
        r.setFillColor("yellow")
        r.setDepth(52)
        l1 = Path(Point(920,300), Point(1080, 300))
        l1.setBorderWidth(5)
        l1.setDepth(51)
        l1.setBorderColor("gold")
        l1.move(176,100)
        #window
        def windows(x,y):
            win = Layer()
            wa= Rectangle(30,45 , Point(1000,645))
            wa.setFillColor("lightblue")
            v = Path(Point(985,645),Point(1015,645))
            win.add(wa)
            win.add(v)
            win.move(x,y)
            hotel.add(win)
        windows(-220,0)
        windows(-220,-70)
        windows(-220,-140)
        windows(-220,-210)
        windows(-150,0)
        windows(-150,-70)
        windows(-150,-140)
        windows(-150,-210)
        hotel.add(r)
        hotel.add(l1)
    right_bldg()

    ## left bldg
    def left_bldg():
        r = Rectangle(150,300, Point(1000, 500))
        r.setFillColor("navy")
        r.move(-176,50)
        r.setDepth(52)
        l1 = Path(Point(920,300), Point(1080, 300))
        l1.setBorderWidth(5)
        l1.setDepth(51)
        l1.setBorderColor("gold")
        l1.move(-176,100)
        #window
        def windows(x,y):
            win = Layer()
            wa= Rectangle(30,45 , Point(1000,645))
            wa.setFillColor("lightblue")
            v = Path(Point(985,645),Point(1015,645))
            win.add(wa)
            win.add(v)
            win.move(x,y)
            hotel.add(win)
        windows(220,0)
        windows(220,-70)
        windows(220,-140)
        windows(220,-210)
        windows(150,0)
        windows(150,-70)
        windows(150,-140)
        windows(150,-210)
        hotel.add(r)
        hotel.add(l1)
        
    left_bldg()
    Miraculous_world.add(hotel)
    hotel.moveTo(x,y)

## this creats the market
def Market(x, y):
    market = Layer()
    roof=Polygon(Point(525,3),Point(500,33),Point(660,33),Point(680,13),Point(810,13),Point(790,33),Point(950,33),Point(975,3))
    roof.setFillColor("darkgreen")
    ##
    front_wll1=Rectangle(160,80,Point(580,73))
    front_wll1.setFillColor("cyan")
    ##
    front_wll2=Rectangle(135,80,Point(740,53))
    front_wll2.setFillColor("blue")
    front_wll2.setDepth(11)
    ##
    front_wll2.setDepth(51)
    front_wll3=Rectangle(160,80,Point(870,73))
    front_wll3.setFillColor("cyan")
    ##
    side1=Polygon(Point(660,33),Point(680,13),Point(680,93),Point(660,113))
    side1.setFillColor("brown")
    ##
    side2=Polygon(Point(950,33),Point(975,3),Point(975,83),Point(950,113))
    side2.setFillColor("black")
    ##
    market.add(roof)
    market.add(front_wll1)
    market.add(front_wll2)
    market.add(front_wll3)
    market.add(side1)
    market.add(side2)
    ## windows
    window1= Rectangle(25,30)
    window1.setFillColor("lightblue")
    window1.moveTo(520,55)

    window1.setDepth(49)
    market.add(window1)

    wl1 = Path(Point(533,55),Point(507,55))
    wl1.setDepth(48)
    market.add(wl1)
    ##
    window2 = window1.clone()
    window2.moveTo(550,55)
    market.add(window2)

    wl2 = Path(Point(563,55),Point(537,55))
    wl2.setDepth(48)
    market.add(wl2)
    ##
    window3 = window1.clone()
    window3.moveTo(580,55)
    market.add(window3)

    wl3 = Path(Point(593,55),Point(567,55))
    wl3.setDepth(48)
    market.add(wl3)
    ##
    window4 = window1.clone()
    window4.moveTo(610,55)
    market.add(window4)

    wl4 = Path(Point(623,55),Point(597,55))
    wl4.setDepth(48)
    market.add(wl4)
    ##
    window5 = window1.clone()
    window5.moveTo(640, 55)
    market.add(window5)

    wl5 = Path(Point(653,55),Point(627,55))
    wl5.setDepth(48)
    market.add(wl5)
    ##

    window6 = window1.clone()
    window6.moveTo(520, 95)
    market.add(window6)

    wl6 = Path(Point(533,95),Point(507,95))
    wl6.setDepth(48)
    market.add(wl6)
    ##
    window7 = window1.clone()
    window7.moveTo(550, 95)
    market.add(window7)

    wl7 = Path(Point(563,95),Point(537,95))
    wl7.setDepth(48)
    market.add(wl7)
    ##
    window8 = window1.clone()
    window8.moveTo(580, 95)
    market.add(window8)

    wl8 = Path(Point(593,95),Point(567,95))
    wl8.setDepth(48)
    market.add(wl8)
    ##
    window9 = window1.clone()
    window9.moveTo(610,95)
    market.add(window9)

    wl9 = Path(Point(623,95),Point(597,95))
    wl9.setDepth(48)
    market.add(wl9)
    ##
    window10 = window1.clone()
    window10.moveTo(640, 95)
    market.add(window10)

    wl10 = Path(Point(653,95),Point(627,95))
    wl10.setDepth(48)
    market.add(wl10)

    ##
    window11 = window1.clone()
    window11.moveTo(810, 55)
    market.add(window11)

    wl11 = Path(Point(823,55),Point(797,55))
    wl11.setDepth(48)
    market.add(wl11)
    ##
    window12 = window1.clone()
    window12.moveTo(840, 55)
    market.add(window12)

    wl12 = Path(Point(853,55),Point(827,55))
    wl12.setDepth(48)
    market.add(wl12)
    ##
    window13 = window1.clone()
    window13.moveTo(870, 55)
    market.add(window13)

    wl13 = Path(Point(883,55),Point(857,55))
    wl13.setDepth(48)
    market.add(wl13)
    ##
    window14 = window1.clone()
    window14.moveTo(900,55)
    market.add(window14)

    wl14 = Path(Point(913,55),Point(887,55))
    wl14.setDepth(48)
    market.add(wl14)
    ##

    window15 = window1.clone()
    window15.moveTo(930, 55)
    market.add(window15)

    wl15 = Path(Point(943,55),Point(917,55))
    wl15.setDepth(48)
    market.add(wl15)

    ##
    window16 = window1.clone()
    window16.moveTo(810, 95)
    market.add(window16)

    wl16 = Path(Point(823,95),Point(797,95))
    wl16.setDepth(48)
    market.add(wl16)
    ##
    window17 = window1.clone()
    window17.moveTo(840, 95)
    market.add(window17)

    wl17 = Path(Point(853,95),Point(827,95))
    wl17.setDepth(48)
    market.add(wl17)
    ##
    window18 = window1.clone()
    window18.moveTo(870, 95)
    market.add(window18)

    wl18 = Path(Point(883,95),Point(857,95))
    wl18.setDepth(48)
    market.add(wl18)
    ##
    window19 = window1.clone()
    window19.moveTo(900, 95)
    market.add(window19)

    wl19 = Path(Point(913,95),Point(887,95))
    wl19.setDepth(48)
    market.add(wl19)
    ##
    window20 = window1.clone()
    window20.moveTo(930, 95)
    market.add(window20)

    wl20 = Path(Point(943,95),Point(917,95))
    wl20.setDepth(48)
    market.add(wl20)
    ## top board
    board=Rectangle(380,50,Point(740,-5))
    board.setFillColor("darkgoldenrod")
    market.add(board)
    ## text
    text = Text("Tom & Sabine Boulangerie Patisserie", 18)

    text.setFontColor("white")
    market.add(text)
    text.moveTo(740, -5)
    text.setDepth(9)
    ## dor
    dor_right=Polygon(Point(740,32),Point(770,32),Point(780,40),Point(780,90),Point(740,90))
    dor_right.setFillColor("skyblue")
    market.add(dor_right)
    dor_left=Polygon(Point(700,40),Point(710,32),Point(740,32),Point(740,90),Point(700,90))
    dor_left.setFillColor("skyblue")
    market.add(dor_left)
    ## dor handle
    dor_handle_right = Path(Point(995,677.5), Point(995, 662.5))
    dor_handle_right.moveTo(748, 70)
    dor_handle_right.setDepth(47)
    dor_handle_right.setBorderWidth(5)
    dor_handle_left = dor_handle_right.clone()
    dor_handle_left.moveTo(732, 70)
    ##
    market.add(dor_handle_right)
    market.add(dor_handle_left)
    ## 
    Miraculous_world.add(market)
    market.moveTo(x, y)

## this adds the roads to our world
def Roads():
    ## road
    roadA=RoadA()
    Miraculous_world.add(roadA)
    roadA.moveTo(650,490)
    ##
    road_lin1 = Polygon(Point(450, 490), Point(530, 490), Point(520, 500), Point(440, 500))
    Miraculous_world.add(road_lin1)
    road_lin1.setFillColor("white")
    ##
    road_line2 = road_lin1.clone()
    Miraculous_world.add(road_line2)
    road_line2.moveTo(280, 490)
    ##
    road_line3 = road_lin1.clone()
    Miraculous_world.add(road_line3)
    road_line3.moveTo(110, 490)
    ##
    road_line4 = road_lin1.clone()
    Miraculous_world.add(road_line4)
    road_line4.moveTo(-70, 490)
    ##
    road_line5 = road_lin1.clone()
    Miraculous_world.add(road_line5)
    road_line5.moveTo(620, 490)
    ##
    road_line6 = road_lin1.clone()
    Miraculous_world.add(road_line6)
    road_line6.moveTo(790, 490)
    ##
    road_line7 = road_lin1.clone()
    Miraculous_world.add(road_line7)
    road_line7.moveTo(960, 490)
    ##
    road_line8 = road_lin1.clone()
    Miraculous_world.add(road_line8)
    road_line8.moveTo(1130, 490)
    ##
    road_line9 = road_lin1.clone()
    Miraculous_world.add(road_line9)
    road_line9.moveTo(1300, 490)
    ##
    road_line10 = Polygon(Point(750,300), Point(700,200), Point(680,200), Point(630, 300))
    road_line10.scale(0.5)
    road_line10.setFillColor("white")
    road_line10.setDepth(50)
    road_line10.moveTo(748, 450)
    Miraculous_world.add(road_line10)
    ##
    road_line11 = Polygon(Point(740,300), Point(710,200), Point(670,200), Point(640, 300))
    road_line11.scale(0.2)
    road_line11.setFillColor("white")
    road_line11.setDepth(50)
    road_line11.moveTo(728, 365)
    Miraculous_world.add(road_line11)
    ##
    roadB = RoadB()
    Miraculous_world.add(roadB)
    roadB.moveTo(90, 265)
    roadB.rotate(-3)
    
    ##
    sideWalk1 = side_walk1()
    Miraculous_world.add(sideWalk1)
    sideWalk1.moveTo(666, 336)
    sideWalk1.setDepth(52)
    ##
    sidewalk2 = side_walk2()
    Miraculous_world.add(sidewalk2)
    sidewalk2.moveTo(763, 335)
    sidewalk2.setDepth(52)
    ##
    fens1 = Fens1()
    Miraculous_world.add(fens1)
    fens1.moveTo(-240,20)
    fens2 = Fens2()
    Miraculous_world.add(fens2)
    fens2.moveTo(-650, 20)
    ##
    Hotel_entrance = Entrance1()
    Hotel_entrance.moveTo(380,460)
    Hotel_entrance.scale(1.2)
    Miraculous_world.add(Hotel_entrance)
    Hotel_entrance.setDepth(51)
    ##
    entrance = Polygon(Point(750, 400), Point(750, 380), Point(950, 380), Point(960, 399))
    entrance.setFillColor("black")
    entrance.setBorderColor("black")
    Miraculous_world.add(entrance)
    entrance.setDepth(50)

## this creats the parking and the sign
def Parking(x, y):
    Park = Layer()
    park = Polygon(Point(100, 700),Point(900, 700), Point(1000, 500), Point(250, 500))
    park.setFillColor("darkgrey")
    def line(point1,point1b,point2,point2b,border,color):
        lin =Layer()
        l= Path(Point(point1,point1b),Point(point2,point2b))
        l.setBorderWidth(border)
        l.setBorderColor(color)
        lin.add(l)
        lin.setDepth(49)
        return(lin)
    line1 = line(300, 698, 400, 502, 7 , "white")
    ##
    line2 = line(500, 698, 600, 502, 7, "white")
    ##
    line3 = line(700, 698, 800, 502, 7 ,"white")
    ##
    Park.add(line1)
    Park.add(line2)
    Park.add(park)
    Park.add(line3)
    Park.moveTo(x, y)
    Miraculous_world.add(Park)
    ##
    sign = Layer()
    pole = line(1000, 650, 1000, 500, 20, "black")
    ##
    board = Square(270)
    board.setFillColor("navy")
    board.setDepth(49)
    board.setBorderWidth(5)
    board.moveTo(1000, 450)
    ##
    info = Layer()
    title = Text("Miraculous world residents: ", 17)
    title.setFontColor("white")
    title.moveTo(1000, 350)
    title.setDepth(48)
    ##
    name1 = Text("1, Lady Bug ", 10)
    name1.setFontColor("white")
    name1.setDepth(48)
    name1.moveTo(1000, 380)
    ##
    name2 = Text("2, Cat Noir", 10)
    name2.setFontColor("white")
    name2.setDepth(48)
    name2.moveTo(1000, 410)
    ##
    name3 = Text("3, Viperion ", 10)
    name3.setFontColor("white")
    name3.setDepth(48)
    name3.moveTo(1000, 440)
    ##
    name4 = Text("4, Rena Rouge", 10)
    name4.setFontColor("white")
    name4.setDepth(48)
    name4.moveTo(1000, 470)
    ##
    name5 = Text("5, Hawk Moth", 10)
    name5.setFontColor("white")
    name5.setDepth(48)
    name5.moveTo(1000, 500)
    ##
    text_status = Text("The mysterious town!", 20)
    text_status.setFontColor("gold")
    text_status.moveTo(1000, 550)
    text_status.setDepth(48)
    ##
    sign.add(pole)
    sign.add(board)
    info.add(title)
    info.add(name1)
    info.add(name2)
    info.add(name3)
    info.add(name4)
    info.add(name5)
    info.add(text_status)
    info.move(0, 0)
    info.setDepth(46)
    sign.add(info)
    sign.setDepth(47)
    sign.moveTo(150, 70)
    Miraculous_world.add(sign)

## this creats and adds the cars to our world
def Car1(x, Speed, color):
    car1 = Layer()
    body = Polygon(
    Point(650, 350), 
    Point(750,350), 
    Point(790, 390), 
    Point(840, 390), 
    Point(840,430), 
    Point(630, 430), 
    Point(630,370)
    )
    body.setFillColor( color)

    ## adds tires
    tire1= Circle(20, Point(780, 430))
    tire1.setFillColor("black")
    tire2 = Circle(20, Point(660, 430))
    tire2.setFillColor("black")

    ## adds windows
    window1 = Polygon(
    Point(750, 358),
    Point(782, 390),
    Point(750,390)

    )
    window2 = Polygon(
    Point(735,358),
    Point(735,390),
    Point(710,390),
    Point(710,358)

    )
    window3 = Polygon(
    Point(650,358),
    Point(695,358),
    Point(695,390),
    Point(638,390),
    Point(638,370)
    )

    window1.setFillColor("white")
    window2.setFillColor("white")
    window3.setFillColor("white")

    ## adds inner_tire circls
    iner_tire1 = Circle(15, Point(780,430))
    iner_tire1.setFillColor("white")
    iner_tire2 = Circle(15, Point(660,430))
    iner_tire2.setFillColor("white")

    ## adds tire lines
    line1 = Path( Point(780,430),Point (780,415))
    line1.setBorderWidth(2)
    line1a = Path( Point(780,430),Point (780,445))
    line1a.setBorderWidth(2)
    line2 = Path( Point(780,430),Point (765,430))
    line2.setBorderWidth(2)
    line2a = Path( Point(780,430),Point (795,430))
    line2a.setBorderWidth(2)
    line3 = Path( Point(660,430),Point (660,415))
    line3.setBorderWidth(2)
    line3a = Path( Point(660,430),Point (660,445))
    line3a.setBorderWidth(2)
    line4 = Path( Point(660,430),Point (645,430))
    line4.setBorderWidth(2)
    line4a = Path( Point(660,430),Point (675,430))
    line4a.setBorderWidth(2)

    ## this section adds the componenets of the car to the layehotel.
    car1.add(body)
    car1.add(tire1)
    car1.add(tire2)
    car1.add(window1)
    car1.add(window2)
    car1.add(window3)
    car1.add(iner_tire1)
    car1.add(iner_tire2)
    car1.add(line1)
    car1.add(line1a)
    car1.add(line2)
    car1.add(line2a)
    car1.add(line3)
    car1.add(line3a)
    car1.add(line4)
    car1.add(line4a)

    ## this section runs the cars motion and the tires rotation
    time.sleep(3)
    car1.moveTo(-850,70)
    car1.setDepth(49)
    Miraculous_world.add(car1)
    for _ in range(x):
        line1.rotate(4)
        line1a.rotate(4)
        line2.rotate(4)
        line2a.rotate(4)
        line3.rotate(4)
        line3a.rotate(4)
        line4.rotate(4)
        line4a.rotate(4)
        car1.move(Speed,0)  
def Car2(x, Speed, color, n):
    car = Layer()
    car1 = Polygon(Point(700, 400), Point(1000,400), Point(1000,350), Point(900, 350), Point(900, 300), Point(780, 300), Point(740, 350), Point(700, 350))
    car.add(car1)
    car1.setFillColor(color)
    ##
    win1 = Polygon(Point(760, 350), Point(790, 310), Point(840, 310),Point(840, 350))
    win1.setFillColor("Black")
    car.add(win1)

    ##
    tire1= Circle(20, Point(950, 400))
    tire1.setFillColor("black")
    tire2 = Circle(20, Point(750, 400))
    tire2.setFillColor("black")
    ##
    iner_tire1 = Circle(15, Point(950,400))
    iner_tire1.setFillColor("white")
    iner_tire2 = Circle(15, Point(750,400))
    iner_tire2.setFillColor("white")
    ##
    line1 = Path( Point(950,400),Point (950,385))
    line1.setBorderWidth(2)
    line1a = Path( Point(950,400),Point (950,415))
    line1a.setBorderWidth(2)
    line2 = Path( Point(950,400),Point (935,400))
    line2.setBorderWidth(2)
    line2a = Path( Point(950,400),Point (965,400))
    line2a.setBorderWidth(2)
    line3 = Path( Point(750,400),Point (750,385))
    line3.setBorderWidth(2)
    line3a = Path( Point(750,400),Point (750,415))
    line3a.setBorderWidth(2)
    line4 = Path( Point(750,400),Point (735,400))
    line4.setBorderWidth(2)
    line4a = Path( Point(750,400),Point (765,400))
    line4a.setBorderWidth(2)
    ##
    car.add(tire1)
    car.add(tire2)
    car.add(iner_tire1)
    car.add(iner_tire2)
    car.add(line1)
    car.add(line1a)
    car.add(line2)
    car.add(line2a)
    car.add(line3)
    car.add(line3a)
    car.add(line4)
    car.add(line4a)
    ##
    car.scale(0.8)
    car.moveTo(650,150)
    car.setDepth(50)
    Miraculous_world.add(car)
    ##
    def go():
            for _ in range(x):
                line1.rotate(-3)
                line1a.rotate(-3)
                line2.rotate(-3)
                line2a.rotate(-3)
                line3.rotate(-3)
                line3a.rotate(-3)
                line4.rotate(-3)
                line4a.rotate(-3)
                car.move(Speed,0)
    ##
    if n == 1:
        go()
        Car1(500, 18, "green")
        go()
    else:
        go()

## this creats the sky 
def Sky():
    sky = Rectangle(1300, 400)
    sky.moveTo(650, 135)
    sky.setDepth(52)
    sky.setFillColor("lightblue")
    sky.setBorderColor("lightblue")
    ##
    Sun = Layer()
    sun = Circle(30)
    sun.moveTo(250, 50)
    sun.setBorderColor("gold")
    sun.setFillColor("yellow")
    ##
    raySE = Path(Point(275,75), Point(290,90))
    raySE.setBorderWidth(5)
    raySE.setBorderColor("yellow")
    rayNE = Path(Point(275,25), Point(290,10))
    rayNE.setBorderWidth(5)
    rayNE.setBorderColor("yellow")
    rayNW = Path(Point(225,25), Point(210,10))
    rayNW.setBorderWidth(5)
    rayNW.setBorderColor("yellow")
    raySW = Path(Point(225,75), Point(210,90))
    raySW.setBorderWidth(5)
    raySW.setBorderColor("yellow")
    ##
    Sun.add(raySE)
    Sun.add(rayNE)
    Sun.add(rayNW)
    Sun.add(raySW)
    Sun.add(sun)
    Sun.scale(1.2)
    Sun.moveTo(400, -10)
   ##
    Miraculous_world.add(sky)
    Miraculous_world.add(Sun)

## this function calls all the above functions to get theme in to the motion
def Play():
    Sky()
    Market(300, 255)
    Hotel(-710,-305)
    Roads()
    Parking(10,40)
    Cloud(600, 70, "white")
    Cloud(700, 50, "white")
    Cloud(-40, -70, "white")
    Cloud(1000, -70, "white")
    Cloud(800, -70, "white")
    Car1(400, 5, "pink")
    time.sleep(1)
    Car2(180, -6, "navy", 1)   
    Car1(150, 14, "navy")
    Car2(180, -10, "yellow", 0)  

## this, the very last line calls the above function to make all the our functions run.
Play()
