import Data.Char

 -- Hazi feladat distance
distance :: (Integer, Integer) -> (Integer, Integer) -> Double
distance (a1, b1) (a2, b2) = sqrt( fromIntegral ((a1-a2)^2 + (b1-b2)^2) )


{-
    BEEPITETT FUGGVENYEK
-} 

-- felfele kerekit -> 2
-- ceiling 1.3

-- lefele kerekit -> 1
-- floor 1.3

-- levagja a nem egesz reszt -> 1
-- truncate 1.3

-- matematikai kerekites -> 2
-- round 1.5

rounding :: Double -> (Integer, Integer, Integer, Integer)
rounding a = (ceiling a, floor a, truncate a, round a)

-- MINDENT CSAK EGYSZER TUDUNK DEFINIALNI - csak egyszer lehet nevet kotni (single assignment)

-- ASCI kod alapjan megadja a meglelelo karakter -> U
-- chr 85

-- Simabol ASCI -> 85
-- ord U

-- exponencialis fuggveny
-- exp 1 

-- 0..9 karaktereket tudja Int-te konvertalni, minden masra exception -> 1
-- digitToInt '1'

-- if
is0 :: Int -> Bool
is0 a = if (a == 0) then True else False

-- pattern matching
is0' :: Int -> Bool
is0' 0 = True
is0' _ = False

-- case / pattern matching
is0'' :: Int -> Bool
is0'' a = case a of 
    0 -> True
    _ -> False


-- guard
is0''' :: Int -> Bool
is0''' a 
   | a == 0 = True
   | otherwise = False


-- tuplebe mehet tobb tipusu elem is
-- (1, 2, 3, 4, 5, 'b')

-- lista csak egyfele tipusu ertekeket tartalmaz
-- [] ures lista
-- x:xs tobb elemu lista
    -- [1, 2, 3, 4, 5, 6, 7]
    -- 1 : 2 : 3 []
    -- 1 : (2 : (3 : ([])))

-- integer listak fejelemet adja vissza
hd :: [Integer] -> Integer
hd []      = error "Empty list"
hd (x:xs)  = x

-- integerek listajanak "vege"
t1 :: [Integer] -> [Integer]
t1 []     = error "Empty list"
t1 (x:xs) = xs