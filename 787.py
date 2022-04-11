l = []

try:
  while True:
    line = input()
    for numStr in line.split():
      if int(numStr) == -999999:

        # Compute answer
        Tpos = [l[0]]
        Tneg = [l[0]]
        m = l[0]
        for t in range(1, len(l)):
          # Positive number
          if l[t] > 0:
            Tpos.append(max(l[t], l[t]*Tpos[t-1]))
            Tneg.append(min(0, l[t]*Tneg[t-1]))
          else:
            Tpos.append(l[t]*Tneg[t-1])
            Tneg.append(min(l[t]*Tpos[t-1], l[t]))
        print(max(Tpos))

        # Reset variables
        l = []
        
      else:
        l.append(int(numStr))
except EOFError:
  # Do nothing
  a = 3
      
