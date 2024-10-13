
read -p "[1] VF [2] VO: " v

IFS="," 
while read mot1 mot2 mot3; do 
      
    echo $mot1 $mot2 $mot3 $v
    if [ $v -eq 1 ]; then
        cowsay -f $mot1 $mot2
    fi
    if [ $v -eq 2 ]; then
        cowsay -f $mot1 $mot3
    fi
done < $1