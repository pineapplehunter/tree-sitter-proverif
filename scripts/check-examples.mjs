#!/usr/bin/env node
// Usage: npm run test:examples -- /path/to/proverif2.05/examples/pitype
// Raw .m4.pv templates require preprocessing and are intentionally excluded.
import { readdirSync } from 'node:fs';
import { resolve, join, relative } from 'node:path';
import { spawnSync } from 'node:child_process';

if (process.argv.length !== 3) {
  console.error('Usage: npm run test:examples -- /path/to/examples/pitype');
  process.exit(2);
}
const directory = resolve(process.argv[2]);
function files(directory) {
  return readdirSync(directory, { withFileTypes: true }).flatMap(entry => {
    const path = join(directory, entry.name);
    if (entry.isDirectory()) return files(path);
    return entry.name.endsWith('.pv') && !entry.name.endsWith('.m4.pv') ? [path] : [];
  });
}
const examples = files(directory).sort();
if (examples.length === 0) throw new Error(`No .pv examples found in ${directory}`);
let failures = 0;
for (const path of examples) {
  const result = spawnSync('tree-sitter', ['parse', '--quiet', path], { encoding: 'utf8' });
  if (result.error) throw result.error;
  if (result.status !== 0) {
    failures++;
    console.error(`FAIL ${relative(directory, path)}\n${result.stdout}${result.stderr}`);
  }
}
console.log(`${examples.length - failures}/${examples.length} examples parsed without errors (excluding .m4.pv).`);
process.exitCode = failures ? 1 : 0;
