type 'a btree = Empty | Node of 'a * 'a btree * 'a btree

let t_ex = Node(5,
                	Node(3,Node(4,Empty,Empty),Node(5,Empty,Empty)),
                	Node(2,Node(3,Empty,Node(7,Empty,Empty)),Empty));;

let rec at_prof_list (n:int) (t : 'a btree) : int list = 
	match t with 
		| Empty -> []
		| Node (e,g,d) -> if n=0 
			then [e]
			else (at_prof_list (n-1) g) @ (at_prof_list (n-1) d)
;;