inc x = succ x

pythagoreanTriple x y z = if (x*x + y*y) == z*z then True else False

isSolution a b c = if (a * c) + b == 0 then True else False

isSolution' a b c = if a * c + b == 0 then True else False

solution :: Integer -> Integer -> Integer -> Integer -> Bool
solution a b c y = a * (y * y) + b * y + c == 0
-- :t solution 
-- solution :: (Num a, Eq a) => a -> a -> a -> a -> Bool

-- :r VAGY :reaload ujra compileolja a fajlt

-- ket megoldas, parok segitsegevel : par : (a, b)
helper a b c d = d * (((-b) + sqrt(b * b - 4 * a * c)) / (2 * a))

solve a b c = (((-b) + sqrt(b * b - 4 * a * c)) / (2 * a), ((-b) - sqrt(b * b - 4 * a * c)) / (2 * a))
solve2 a b c = (helper a b c 1, helper a b c (-1))

-- racionalis szamok : integer szampar
-- mult es a megszoritasa
mult :: (Integer, Integer) -> (Integer, Integer) -> (Integer, Integer)
mult (a1, b1) (a2, b2) = (a1 * a2, b2 * b2)

mult' :: (Integer, Integer) -> (Integer, Integer) -> (Integer, Integer)
mult' a b = (fst a * fst b, snd a * snd b)

-- fuggvenyt tobb egyenlettel definialunk
and' :: Bool -> Bool -> Bool
and' True True = True
and' True False = False
and' False True = False
and' False False = False

and'' :: Bool -> Bool -> Bool
and'' True True = True
and'' _ _       = False
-- ha a fenti mar nem teljesul, akkor mar False lesz
-- and'' False _   = False

-- and'' _ False = False

