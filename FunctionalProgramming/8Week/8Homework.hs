-- head                 -> elso elem
-- tail                 -> elso elem utan minden
-- last                 -> legutolso elem
-- init                 -> minden az utolso elem elott
-- length [3, 2, 1, 0]  -> hossza
-- null [3, 2, 1]       -> ures-e
-- reverse [3, 2, 1]    -> visszafele kiirja [1, 2, 3]
-- take 2 [3, 2, 1]     -> veszi az elso parameterul kapott elemet -> [3, 2]
-- drop 2 [4, 3, 2, 1]  -> atugorja az elso parameterul kapott elemet [2, 1]
-- maximum              -> legnagyobb elemet adja vissza
-- minimum              -> legkisebb elemet adja vissza
-- sum                  -> lista elemeinek osszege
-- product              -> lista elemeinek szorzata

-- [3, 2, 1] > [2, 10, 100] -> lexikographical osszehasonlitas miatt, ha 3 > 2, onnantol mar mindegy, hogy mi jon utana
-- 4 `elem` [3, 2, 1]       -> False, mert 4-et nem tartalmazza a lista
-- [1..20]
-- [2, 4 .. 20]             -> kettesevel
-- ['a'..'z']
-- take 10 (cycle[1, 2, 3]) -> 10-szer ki fogja irni az 1,2,3-at
-- take 10 (repeat 5)       -> 10-szer ki fogja irni az 5-ot

-- [x | x <- [1..10], x `mod` 7 == 3]

-- boomBangs xs = [ if x < 10 then "BOOM!" else "BANG!" | x <- xs, odd x]   a 10 alatti odd numberek helyere BOOM-ot, a 10-nel nagyobb odd numberrek helyere BANG-et irunk
--                                                                          az x <- xs azert van, mert list a parameter

-- [ x | x <- [10..20], x /= 13, x /= 15, x /= 19]  10 es 20 kozott a szamok, amiben nicns a 13, 15, 19

-- [ x*y | x <- [2,5,10], y <- [8,10,11]]  =>       [16,20,22,40,50,55,80,100,110]  
-- [ x*y | x <- [2,5,10], y <- [8,10,11], x*y > 50] [55,80,100,110]

odds :: [Int] -> [Int]
odds [] = []
odds (x:xs) = if odd x then x : odds xs else odds xs

seged :: [Integer]
seged = take 10000 [x ^ 2 | x <- [2..]]

squarenums :: [Integer] -> [Integer]
squarenums [] = []
squarenums (x:xs) = let res = squarenums xs in 
                        if elem x seged
                        then x : res
                        else res


{--
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
--}
