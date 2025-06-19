#include <stdio.h>

/* Return the number of running process */
int n_running_process(int running[], int length);

/* Sum of array */
int sum(int arr[], int length);

int main()
{
	int n_jobs = 0;
	int n_resources = 1; // Only 1 resource type for simplicity sake

	int available_res = 0;

	printf("Number of Jobs: ");
	scanf("%d", &n_jobs);

	int alloc_process[n_jobs] = {};
	int max_demand[n_jobs] = {};
	int running[n_jobs];

	for (int i = 0; i < n_jobs; ++i) {
		running[i] = 1;
	}

	printf("Available Resources: ");
	scanf("%d", &available_res);

	for (int i = 0; i < n_jobs; ++i) {
		printf("Allocated process for job %d: ", i + 1);
		scanf("%d", &alloc_process[i]);
	}

	for (int i = 0; i < n_jobs; ++i) {
		printf("Maximum demand for job %d: ", i + 1);
		scanf("%d", &max_demand[i]);
	}

	int sum_alloc = sum(alloc_process, n_jobs);
	int total_available = available_res - sum_alloc;
	int at_least_one_allocate = 0;
	while (n_running_process(running, n_jobs) > 0) {
		at_least_one_allocate = 0;
		for (int i = 0; i < n_jobs; ++i) {
			if (running[i] == 1) {
				if (total_available - (max_demand[i] - alloc_process[i]) >= 0) {
					at_least_one_allocate = 1;
					printf("job %d is running...\n", i + 1);
					running[i] = 0;
					total_available += alloc_process[i];
				}
			}
		}

		if (at_least_one_allocate == 1) {
			printf("Safe\n");
			printf("Total device allocated: %d\n", sum_alloc);
			printf("Available Resources: %d\n", available_res);
		} else {
			printf("Unsafe\n");
			break;
		}
	}
		
	return 0;
}

int n_running_process(int running[], int length)
{
	int nonzero_count = 0;
	for (int i = 0; i < length; ++i) {
		if (running[i] == 1)
			nonzero_count++;
	}

	return nonzero_count;
}

int sum(int alloc_process[], int length)
{
	int sum = 0;
	for (int i = 0; i < length; ++i) {
		sum += alloc_process[i];
	}

	return sum;
}
