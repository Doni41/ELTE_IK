-- Defináld egy helyvektor nyújtását konstansszorosára! Legyen a függvény neve
stretch :: (Integer, Integer) -> (Integer) -> (Integer, Integer)
stretch (a, b) (x) = (a * x, b * x)

{--
distance :: (Integer, Integer) -> (Integer, Integer) -> (Floating)
distance (a1, a2) (b1, b2) = sqrt(((b1 - a1) * (b1 - a1)) + ((b2-a2) * (b2-a2))) 
-}

-- Számítsd ki két pont távolságát a síkban! Legyen a függvény neve distance. Tesztek:
distance1 :: (Double, Double) -> (Double, Double) -> (Double)
distance1 (a1, a2) (b1, b2) = sqrt(((b1 - a1) * (b1 - a1)) + ((b2-a2) * (b2-a2))) 

-- Definiáld újra a logikai „vagy” operátortmintaillesztéssel! Legyen a függvény neve or'. Tesztek:
or' :: Bool -> Bool -> Bool
or' False False = False
or' _ _ = True

and' :: Bool -> Bool -> Bool
and' True True = True
and' _ _       = False

-- Definiáld az isSpace függvényt, ami egy bemeneti paraméterről eldönti, hogy space (' ') karakter-e! Tesztek:
isSpace :: Char -> Bool
isSpace x = if(x == ' ') then True else False

{--
Orai plusz, minusz
--}

-- Definiáld a logikai “kizáró vagy” műveletet xor néven! Segítség: xor True True és xor False False eredménye hamis, minden más eset eredménye igaz.
xor :: Bool -> Bool -> Bool
xor True True = False
xor False False = False
xor _ _ = True

-- Definiáld a modDiv függvényt, amely két paramétert vár (legyenek a és b), és visszaad egy párt, melynek első tagja a maradékosan osztva b-vel, és a második a egészosztással elosztva b-vel! Pl. modDiv 5 2 == (1, 2), illetve használhatod a mod és div függvényeket.
modDiv :: Integer -> Integer -> (Integer, Integer)
modDiv a b = ((mod a b) , (div a b))