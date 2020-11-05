import Data.Char
import Data.List

-- isPrefixOf
-- ket parameter elso karakteret osszehasonlitjuk, ha igaz, akkor osszehasonlitjuk a kovetkezo karaktert is
-- ures az barminek a prefix-e
-- isPrefixOf' :: [a] [a] -> Bool
isPrefixOf' :: Eq a => [a] -> [a] -> Bool
isPrefixOf' [] _ = True
isPrefixOf' (x:xs) (y:ys) = if x == y then isPrefixOf xs ys else False

-- evens -> istakbol paros szamok kigyujtese
evens :: [Int] -> [Int]
evens [] = []
evens (x:xs) = if even x then x : evens xs else evens xs

-- evens (x:xs) = let res = evens xs in 
--                    if even x
--                    then x : res
--                    else res

-- első 100 db 3 hatványban melyek szerepelnek
powersOfThree :: [Int]
powersOfThree = take 100 [3 ^ n | n <- [0..] ]

-- adott elem benne van-e a listaban
firstn :: [Int] -> [Int]
firstn [] = []
firstn (x:xs) = let res = firstn xs in
                    if elem x powersOfThree
                    then x : res
                    else res

-- filter
-- adott elemre teljesul-e a feltetel
-- var egy a tipusu fuggvenyt, és bool-lal ter vissza
filter' :: (a -> Bool) -> [a] -> [a]
filter' cond [] = []
filter' cond (x:xs) = let res = filter' cond xs in
                    if cond
                    then x : res
                    else res

evens' l = filter even l
evens'' = filter' even
--evens' l = filter' (even x)

-- isEvens -> atalakitja a listat egy bool listaval
-- minden szamot atalakit arra, hogy paros-e
isEvens :: [Int] -> [Bool]
isEvens [] = []
isEvens (x:xs) = even x : isEvens xs

-- OLYAN FUGGVENYEK? AMIK ELOADASON IS VOLTAK => ELOADAST MEGNEZNI

-- minden szamt egy listaban csereljunk ki egy listaval, amely annyiszor tartalmazza onmagat, amennyis