const main = () => {
  const n = 121;
  let cells = Array(n).fill(0);
  cells[Math.floor(n / 2)] = 1;
  const previous_cells = cells.concat();

  const step = 50;
  console.log(cells.join(""));
  for (let i = 0; i < step; i++) {
    for (let j = 0; j < n; j++) {
      const l = j !== 0 ? cells[j - 1] : cells[n - 1];
      const c = cells[j];
      const r = j !== n - 1 ? cells[j + 1] : cells[0];
      const around = "" + l + c + r;
      const state = parseInt(around, 2);
      // ... -> .
      // ..# -> #
      // .#. -> #
      // .## -> #
      // #.. -> #
      // #.# -> .
      // ##. -> .
      // ### -> .
      previous_cells[j] = (0 < state && state <= 4) ? 1 : 0;
    }
    cells = previous_cells.concat();
    console.log(cells.join(""));
  }
};
main();
