import Data.Char
import Data.List

-- Add meg az hoursMinutes függvényt, aminek nincs bemeneti paramétere, és megadja egy listában az összes lehetséges óra-perc párt!
hoursMinutes :: [(Integer, Integer)]
hoursMinutes = [(x,y) | x <- [0..23], y <- [0..59]]

-- Add meg a fours függvényt, aminek nincs bemeneti paramétere, és megad egy 20 hosszú listát, melyben az 1, 2, 3, 4 számsorozat ismétlődik!
fours :: [Integer]
fours = [ x | x <- [1 .. 20], x <- [1, 2, 3, 4]]

-- Add meg az abcList függvényt, aminek nincs bemeneti paramétere, és visszaadja a sorszámukkal párba állítva az angol ábécé betűit!
-- abcList :: [(Char, Integer)]
abcList = [ (ord(x) - 97 , x) | x <- ['a' .. 'z']]

-- Add meg a divisors függvényt, amely egy egész számot vár bemenetként, és visszaadja az osztóit!
-- divisors :: Integer -> [(Integer, Integer)]
divisors :: Integer -> [Integer]
divisors x = [ y | y <- [1 .. x], x `mod` y == 0 ]

-- Add meg az isPrime' függvényt, amely a paraméteréről eldönti, hogy prím-e! Tipp: hasznos lehet a null függvény, amely eldönti egy listáról, hogy üres-e, vagy a length, amely megadja egy lista hosszát.
isPrime' :: Int -> Bool
isPrime' 1 = False
isPrime' 2 = True
isPrime' n | (length [x | x <- [2 .. n-1], mod n x == 0]) > 0 = False
           | otherwise = True


-- Add meg a compress függvényt, amely egy szöveget tömörít úgy, hogy az egymást követő betűk tárolása darabszám-betű párként van megvalósítva! Tesztek:
{-
compress :: [Char] -> [(Int, [[Char]])]
compress r = [ (length[z], head[z]) | z <- group[r]]
-}

-- twoPower :: [Integer]
twoPower = head [2 ^ x  | x <- [0..], 2 ^ x > 10 ^ 20]