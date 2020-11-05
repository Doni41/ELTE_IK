{-
isSingletonInt :: [Integer] -> Bool
isSingletonInt f[] =  if  then False else True
-}

import Data.Char

isSingletonInt :: [Integer] -> Bool
isSingletonInt [] = False
isSingletonInt (x:xs) = if xs == [] then True else False

toUpperFirst :: [Char] -> [Char]
toUpperFirst [] = []
toUpperFirst (h:t) = toUpper h : t

changeFirst :: [Char] -> [Char]
changeFirst [] = []
changeFirst (h:t) = if isLower h then (toUpper h : t) else (toLower h : t)

-- 
upperHd :: [Char] -> Char
upperHd [] = '?'
upperHd (h:t) = toUpper h

changeHd :: [Char] -> Char
changeHd [] = '?'
changeHd (h:t) = if isLower h then (toUpper h) else (toLower h)




