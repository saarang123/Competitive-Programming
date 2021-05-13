def tower_hanoi(n, A, C, aux):
    if(n==1):
        print("Moves disc 1 from", A, " to", C)
        return
    tower_hanoi(n-1, A, aux, C)
    print("Moves disc", n, " from", A, " to", C)
    tower_hanoi(n-1, aux, C, A)
    
tower_hanoi(4, "A", "C", "B")
    