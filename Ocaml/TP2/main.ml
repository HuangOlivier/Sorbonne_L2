let rec bin_to_int (i : int list) : int =
	match i with 
		| [] -> raise (Invalid_argument "empty list")
		| [h] -> h
		| h::t -> h + 2*(bin_to_int (t)) 
;;

assert (bin_to_int [0; 1; 1] = 6) ;;
assert (bin_to_int [1; 1; 0; 1; 0; 1] = 43) ;;

let rec int_to_bin (i : int) : int list = 
	if i<2 
		then [i]
		else if (i mod 2)=0 
			then 0::(int_to_bin (i/2))
			else 1::(int_to_bin (i/2))
		;;

assert ( bin_to_int (int_to_bin 43) = 43) ;;

let rec comp_bin (l : int list) (n:int) : int list =
	match l with 
		| [] -> if n<0 
			then raise (Invalid_argument "comp_bin")
			else if n=0 
				then []
				else 0::(comp_bin [] (n-1))
		| h::t -> h::(comp_bin t (n-1))
;;

let rec range_inter (a:int) (b:int) : int list =
	if a>b then []
	else a::(range_inter (a+1) b);;


let genere_list (n : int) : int list =
	range_inter 2 n;;

let rec elimine (l:int list) (n:int) : int list =
	match l with 
		| [] -> []
		| h::t -> if (h mod n)=0 
			then elimine t n
			else h::(elimine t n)
;;

assert ((elimine [1; 2; 3; 4; 5; 6] 3) = [1; 2; 4; 5]) ;;

let rec ecreme (l : int list) : int list = 
	match l with 
		| [] -> []
		| h::t -> h::(elimine (ecreme t) h)
;;

let crible (n : int) : int list =
	ecreme (genere_list n)