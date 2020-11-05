import Data.Char
import Data.List

-- Válogasd ki egy listából a páratlan számokat (legyen a függvény neve odds)!
odds :: [Int] -> [Int]
odds [] = []
odds (x:xs) = if odd x then x : odds xs else odds xs

-- Válogasd ki egy listából a négyzetszámokat (legyen a függvény neve squarenums)! Hatékonyság növeléséhez nyugodtan használj segédfüggvényt, vagy lokális definíciót!
seged :: [Integer]
seged = take 10000 [x ^ 2 | x <- [2..]]

-- squarenums []    = []
-- squarenums (x:xs) = if elem x squares
--                     then x : (squarenums xs)
--                     else suqarenums xs

squarenums'' l = filter (\x -> elem x (take 1000 [x ^ 2 | x <- [1..] ]))
-- lambda kifejezes segitsegevel -> nevtelen fgv
squarenums' l = filter (\x -> elem x seged)

-- lokalis fgv deifnicio
squarenum''' l = filter isSquare l where 
    isSquare x = elem x seged

squarenums :: [Integer] -> [Integer]
squarenums [] = []
squarenums (x:xs) = let res = squarenums xs in 
                        if elem x seged
                        then x : res
                        else res

-- minden szamot egy listaban csereljunk ki egy listaval, amely annyiszor tartalmazza onmagat, amennyi az erteke
transform :: [Int] -> [[Int]]
transform []        = []
transform (x:xs)    = take x (repeat x) : transform xs

-- map  -> a tipusu listabol csinalunk b tipusu listat f fgv segitsegevel
map' :: (a -> b) -> [a] -> [b]
map' f     []   =   []
map' f (x:xs)   = f x : map' f xs

-- transform megadasa map-pal
transform' :: [Int] -> [[Int]]
transform' l = map' (\ x -> take x (repeat x)) l

-- upperToLower (nagybetuket alakitsuk kisbetuve, es csak ezeket adjuk vissza)
-- eloszor alakitunk at, es utana szurjuk le a karaktereket
upperToLower :: String -> String
-- upperToLower l = map' toLower l (filter isUpper l)
upperToLower l = (map' toLower) (filter isUpper l)

upperToLower' l = map' toLower l

-- max 
-- foldr fgv-rol kerul majd fel anyag
