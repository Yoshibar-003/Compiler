(*
PROGRAMMER: NinYo Sene Oudom
PROGRAM #: Project 1
DUE DATE: Wednesday, 2/11/2026
INSTRUCTOR: Dr. Zhijiang Dong

Description:
    This program implements an interpreter for a simple stack machine.

Variables:
    stack : List   -- stack of Int values; uses ~1 to represent '*'
    done  : Bool   -- loop control; becomes true when user enters 'x'
    input : String -- one command read from user each loop iteration
    curr  : List   -- temporary pointer used to traverse stack for 'd'
*)

(*
   The class A2I provides integer-to-string and string-to-integer
conversion routines.  To use these routines, either inherit them
in the class where needed, have a dummy variable bound to
something of type A2I, or simpl write (new A2I).method(argument).
*)


(*
   c2i   Converts a 1-character string to an integer.  Aborts
         if the string is not "0" through "9"
*)
class A2I {

     c2i(char : String) : Int {
	if char = "0" then 0 else
	if char = "1" then 1 else
	if char = "2" then 2 else
        if char = "3" then 3 else
        if char = "4" then 4 else
        if char = "5" then 5 else
        if char = "6" then 6 else
        if char = "7" then 7 else
        if char = "8" then 8 else
        if char = "9" then 9 else
        { abort(); 0; }  -- the 0 is needed to satisfy the typchecker
        fi fi fi fi fi fi fi fi fi fi
     };

(*
   i2c is the inverse of c2i.
*)
     i2c(i : Int) : String {
	if i = 0 then "0" else
	if i = 1 then "1" else
	if i = 2 then "2" else
	if i = 3 then "3" else
	if i = 4 then "4" else
	if i = 5 then "5" else
	if i = 6 then "6" else
	if i = 7 then "7" else
	if i = 8 then "8" else
	if i = 9 then "9" else
	{ abort(); ""; }  -- the "" is needed to satisfy the typchecker
        fi fi fi fi fi fi fi fi fi fi
     };

(*
   a2i converts an ASCII string into an integer.  The empty string 
is converted to 0.  Signed and unsigned strings are handled.  The
method aborts if the string does not represent an integer.  Very
long strings of digits produce strange answers because of arithmetic 
overflow.
(*2019Spring*)
*)
     a2i(s : String) : Int {
        if s.length() = 0 then 0 else
	if s.substr(0,1) = "-" then ~a2i_aux(s.substr(1,s.length()-1)) else
        if s.substr(0,1) = "+" then a2i_aux(s.substr(1,s.length()-1)) else
           a2i_aux(s)
        fi fi fi
     };

(*
  a2i_aux converts the usigned portion of the string.  As a programming
example, this method is written iteratively.
*)
     a2i_aux(s : String) : Int {
	(let int : Int <- 0 in	
           {	
               (let j : Int <- s.length() in
	          (let i : Int <- 0 in
		    while i < j loop
			{
			    int <- int * 10 + c2i(s.substr(i,1));
			    i <- i + 1;
			}
		    pool
		  )
	       );
              int;
	    }
        )
     };

(*
    i2a converts an integer to a string.  Positive and negative 
numbers are handled correctly.  
*)
    i2a(i : Int) : String {
	if i = 0 then "0" else 
        if 0 < i then i2a_aux(i) else
          "-".concat(i2a_aux(i * ~1)) 
        fi fi
    };
	
(*
    i2a_aux is an example using recursion.
*)		
    i2a_aux(i : Int) : String {
        if i = 0 then "" else 
	    (let next : Int <- i / 10 in
		i2a_aux(next).concat(i2c(i - next * 10))
	    )
        fi
    };

};


(*
 *  This file shows how to implement a list data type for lists of integers.
 *  It makes use of INHERITANCE and DYNAMIC DISPATCH.
 *
 *  The List class has 4 operations defined on List objects. If 'l' is
 *  a list, then the methods dispatched on 'l' have the following effects:
 *
 *    isNil() : Bool		Returns true if 'l' is empty, false otherwise.
 *    head()  : Int		Returns the integer at the head of 'l'.
 *				If 'l' is empty, execution aborts.
 *    tail()  : List		Returns the remainder of the 'l',
 *				i.e. without the first element.
 *    cons(i : Int) : List	Return a new list containing i as the
 *				first element, followed by the
 *				elements in 'l'.
 *
 *  There are 2 kinds of lists, the empty list and a non-empty
 *  list. We can think of the non-empty list as a specialization of
 *  the empty list.
 *  The class List defines the operations on empty list. The class
 *  Cons inherits from List and redefines things to handle non-empty
 *  lists.
 *)


class List {
   -- Define operations on empty lists.

   isNil() : Bool { true };

   -- Since abort() has return type Object and head() has return type
   -- Int, we need to have an Int as the result of the method body,
   -- even though abort() never returns.

   head()  : Int { { abort(); 0; } };

   -- As for head(), the self is just to make sure the return type of
   -- tail() is correct.

   tail()  : List { { abort(); self; } };

   -- When we cons and element onto the empty list we get a non-empty
   -- list. The (new Cons) expression creates a new list cell of class
   -- Cons, which is initialized by a dispatch to init().
   -- The result of init() is an element of class Cons, but it
   -- conforms to the return type List, because Cons is a subclass of
   -- List.

   cons(i : Int) : List {
      (new Cons).init(i, self)
   };

};


(*
 *  Cons inherits all operations from List. We can reuse only the cons
 *  method though, because adding an element to the front of an emtpy
 *  list is the same as adding it to the front of a non empty
 *  list. All other methods have to be redefined, since the behaviour
 *  for them is different from the empty list.
 *
 *  Cons needs two attributes to hold the integer of this list
 *  cell and to hold the rest of the list.
 *
 *  The init() method is used by the cons() method to initialize the
 *  cell.
 *)

class Cons inherits List {

   car : Int;	-- The element in this list cell

   cdr : List;	-- The rest of the list

   isNil() : Bool { false };

   head()  : Int { car };

   tail()  : List { cdr };

   init(i : Int, rest : List) : List {
      {
	 car <- i;
	 cdr <- rest;
	 self;
      }
   };

};



(*
 *  The Main class shows how to use the List class. It creates a small
 *  list and then repeatedly prints out its elements and takes off the
 *  first element of the list.
 *)

(*class Main inherits IO {

   mylist : List;

   -- Print all elements of the list. Calls itself recursively with
   -- the tail of the list, until the end of the list is reached.

   print_list(l : List) : Object {
      if l.isNil() then out_string("\n")
                   else {
			   out_int(l.head());
			   out_string(" ");
			   print_list(l.tail());
		        }
      fi
   };

   -- Note how the dynamic dispatch mechanism is responsible to end
   -- the while loop. As long as mylist is bound to an object of 
   -- dynamic type Cons, the dispatch to isNil calls the isNil method of
   -- the Cons class, which returns false. However when we reach the
   -- end of the list, mylist gets bound to the object that was
   -- created by the (new List) expression. This object is of dynamic type
   -- List, and thus the method isNil in the List class is called and
   -- returns true.

   main() : Object {
      {
	 mylist <- new List.cons(1).cons(2).cons(3).cons(4).cons(5);
	 while (not mylist.isNil()) loop
	    {
	       print_list(mylist);
	       mylist <- mylist.tail();
	    }
	 pool;
      }
   };

};
*)





(* add your solution below *)

-- this for comments

class Main inherits IO{
    main() : Object {
        {
            let stack : List <- new List in -- stack stores integers
            let done : Bool <- false in     -- loop control flag.
            let input : String in           -- store user inputs
            let curr : List in              -- temp pointer for display stack 

            -- main interpreter loop
            while not done loop
            {   
                -- prompt user
                out_string("> ");
                
                -- read the command per line
                input <- in_string();

                -- exit command
                if input = "x" then 
                    {
                    out_string("COOL program successfully executed.");
                    done <- true;
                    }
                else 
                    -- display command
                    if input = "d" then 
                        {
                            curr <- stack;
                            while not curr.isNil() loop
                                {   
                                    if curr.head() = ~1 then -- if value = -1 print *
                                        out_string("*\n")
                                    else 
                                        {
                                            out_int(curr.head());
                                            out_string("\n");
                                        }
                                    fi;
                                    curr <- curr.tail();
                                }
                            pool;
                        }
                else 
                    -- evaluate command
                    if input = "e" then
                        {   
                            -- only evaluate if stack is not empty
                            if not stack.isNil() then
                            {   
                                if stack.head() = ~1 then
                                {    
                                    -- pop
                                    stack <- stack.tail();

                                    -- first
                                    if not stack.isNil() then
                                    {
                                        let first : Int <- stack.head() in
                                        {
                                            stack <- stack.tail();

                                            if not stack.isNil() then
                                            {
                                                let second : Int <- stack.head() in
                                                {
                                                    stack <- stack.tail();

                                                    -- result
                                                    stack <- stack.cons(first * second);
                                                };
                                            }
                                            else
                                                0
                                            fi;
                                        };
                                    }
                                    else 
                                        0
                                    fi;
                                }
                                else
                                    0
                                fi;
                            }
                            else
                                0
                            fi;
                        }
                else 
                    -- convert * into -1
                    if input = "*" then
                        -- put ~1(-1) instead of * 
                        stack <- stack.cons(~1) 
                    else
                        {   
                            -- convert string into integer
                            let converter : A2I <- new A2I in
                                {
                                let clean : String <- 
                                    (if input.length() = 0 then input else
                                        if input.substr(input.length()-1, 1) = "\n"
                                        then input.substr(0, input.length()-1)
                                        else input
                                        fi
                                    fi) 
                                in
                                let number : Int <- converter.a2i(clean) in
                                    stack <- stack.cons(number);
                                };
                            }
                        fi 
                    fi 
                fi 
            fi;
        }
    pool;
    }
    };
};
