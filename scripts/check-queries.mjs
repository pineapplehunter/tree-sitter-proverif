#!/usr/bin/env node
// Compile every shipped query against the parser and exercise it on a real model.
import { readdirSync } from 'node:fs';
import { spawnSync } from 'node:child_process';

function run(args) {
  const result = spawnSync('tree-sitter', args, { stdio: 'inherit' });
  if (result.error) throw result.error;
  if (result.status !== 0) process.exit(result.status ?? 1);
}

run(['parse', '--quiet', 'test/fixtures/editor.pv']);
for (const file of readdirSync('queries').filter(file => file.endsWith('.scm')).sort()) {
  console.log(`Checking queries/${file}`);
  run(['query', '--quiet', `queries/${file}`, 'test/fixtures/editor.pv']);
}
