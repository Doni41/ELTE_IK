-- Listak :
--      - Intervallumok: 
--          - [1..20] 
--          - [1, 3 .. 9] -> [1, 3, 5, 7, 9]
--          - [9 .. 1] -> []
--          - :i Enum -> amiket fel lehet sorolni .. operatorral
--          - ['0' .. '9'] -> "0123456789" 


import Data.Char

-- Szamjegy-e a karakter parametere egy fuggvenynek
isNum :: Char -> Bool
isNum n = elem n ['0' .. '9']

-- Betu-e a parametere egy fuggvenynek?
isLetter' :: Char -> Bool
isLetter' n = elem n (['a' .. 'z'] ++ ['A' .. 'Z'])

-- Hatvan osztoi
-- [n | n <- [1 .. 60], 60 `mod` n == 0 ]

-- Harom hatvanyai
-- take 20 [ 3 ^ n | n <- [0 ..]]
powersOfThree :: [Integer]
powersOfThree = [ 3 ^ n | n <- [0 .. 10] ]

-- [ (x, n) | n <- [1 .. ], x <- [True, False] ]

-- Tiz hosszu lista, True es False felvaltva
trueEsFalse = [n `mod` 2 == 1 | n <- [1 .. 10]]
-- [even n | n<-[1..10]] :: [Bool]
-- take 10 [ (x,n) | n <- [1..], x <- [True, False] ]

-- Melyik harom hatvany nagyobb, mint 10^20
firstElem = head [ 3 ^ n | n <- [0..], 3 ^ n > 10 ^ 20 ]

-- Alakirs egy szoveget csupa nagybetusse
transform' :: String -> String
transform' s = [toUpper x | x <- s]

