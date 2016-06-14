import Data.Time

merge [] ys = ys
merge xs [] = xs
merge (x:xs) (y:ys) = if x <= y
                      then x : merge xs (y:ys)
                      else y : merge (x:xs) ys
mergesort [] = []
mergesort [x] = [x]
mergesort xs = let
               (as,bs) = splitAt(length xs `quot` 2) xs
               in merge (mergesort as)(mergesort bs)

wordtolist string = map read $ words string :: [Int]

main = do
       start <- getCurrentTime
       vet <- readFile "sample3.txt"
       let a = lines vet
       let b = map(wordtolist) a
       let c = map(mergesort) b
       stop <- getCurrentTime
       print $ diffUTCTime stop start
