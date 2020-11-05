doubleMe x = x + x

doubleUs x y = x*2 + y*2

doubleSmallNumber x = if x > 100
    then x 
    else x*2

doubleSmallNumber' x = (if x > 100 then x else x*2) + 10

conanO'Briedn = "It's a-me, Conan O'Brien!"

inc x = x + 1

double x = x * 2

area x y = (x * y) * (x * y)

-- min 9 10
-- succ 9 -> 10, az utana kovetkezo szam
-- max 9 10
-- doubleMe x = x + x
-- div 92 10 -> 9, DE lehet igy is meghivni: 92 `div` 10