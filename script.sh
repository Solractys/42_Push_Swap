#!/bin/bash

# --- Configuration ---
NUM_RUNS=100
NUM_COUNT=3
NUM_RANGE="0-2147483647"
RESULTS_FILE="results.txt"
PUSH_SWAP_BIN="./push_swap"
CHECKER_BIN="./checker_linux"

# --- Check for required programs ---
if [ ! -f "$PUSH_SWAP_BIN" ]; then
    echo "Error: $PUSH_SWAP_BIN not found."
    exit 1
fi
if [ ! -f "$CHECKER_BIN" ]; then
    echo "Error: $CHECKER_BIN not found."
    exit 1
fi

# --- Main Script ---

# Clear the results file
> "$RESULTS_FILE"

echo "Running $NUM_RUNS tests with $NUM_COUNT numbers..."

for i in $(seq 1 $NUM_RUNS)
do
    # 1. Generate numbers
    ARG=$(shuf -i "$NUM_RANGE" -n "$NUM_COUNT" | paste -sd ' ')

    # 2. Run checker
    RESULT=$( "$PUSH_SWAP_BIN" $ARG | "$CHECKER_BIN" $ARG )

    # 3. If OK, calculate size and save
    if [ "$RESULT" = "OK" ]; then
        COUNT=$( "$PUSH_SWAP_BIN" $ARG | wc -l )
        echo $COUNT >> "$RESULTS_FILE"
        echo "Run $i/$NUM_RUNS: OK ($COUNT moves)"
    else
        echo "Run $i/$NUM_RUNS: $RESULT"
    fi
done

echo "---"
echo "All tests complete. Calculating Best, Worst, and Average..."
echo "---"

# 4. Use awk to calculate Min, Max, and Average
awk '
    BEGIN { 
        # Initialize variables
        min = 2147483647    # Start with a huge number
        max = 0             # Start with zero
        sum = 0
    }
    { 
        # Add to sum
        sum += $1 
        
        # Check for Best Case (Min)
        if ($1 < min) {
            min = $1
        }
        
        # Check for Worst Case (Max)
        if ($1 > max) {
            max = $1
        }
    } 
    END { 
        if (NR > 0) {
            print "Total Successful Runs:", NR
            print "-----------------------------"
            print "Best Case  (Min):", min
            print "Worst Case (Max):", max
            print "Average         :", int(sum / NR) 
        } else {
            print "No successful (OK) runs were recorded."
        }
    }
' "$RESULTS_FILE"

rm $RESULTS_FILE
