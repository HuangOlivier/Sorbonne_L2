echo "Les albums recommandés des Beatles sont :" 
ls 1001_Albums_You_Must_Hear_Before_You_Die/*-[A-Za-z]-*.flac

count=0

for test in 1001_Albums_You_Must_Hear_Before_You_Die/*.flac
do
	echo $test
	count=$((count + 1))
done

echo "il y a $count albums"  #1065

moyenne_taille_fichier=0;




