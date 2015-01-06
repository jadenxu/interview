// use external sort to sort this 20GB

// Step 1. read 1 GB into the main memory, sort it by some sorting algorithm
// Step 2. repeat step 1 untill 20 1GB are sorted
// Step 3. read first 0.025GB (20 * 0.025 = 0.5GB) for each sorted chunk, perform 
// 20-way merge. When any of them is empty, get next 0.025GB from its chunk. When 
// the writing array is full, writing it into the memory
