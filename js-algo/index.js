const n = 4;
const m = 4;
const recursive = (arr) => {
  const tempSet = new Set();
  arr.map((a) => tempSet.add(a));
  if (tempSet.size !== arr.length) return; // 중복 있으면 종료
  if (arr.length === m) {
    console.log(arr.reduce((acc, cur) => `${acc} ${cur}`));
  }
  for (let i = 1; i <= n; i++) {
    recursive([...arr, i]);
  }
};

recursive([]);
