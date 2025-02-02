# Checker for Mac

ARG="5 2 7 1 6 3 9 4 8 10 -3 88"
./push_swap ${=ARG} | ./checker_Mac ${=ARG}

# Checker for Linux

ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG

# Great Visualizer

https://push-swap42-visualizer.vercel.app
