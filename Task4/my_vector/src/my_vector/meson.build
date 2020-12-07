gtest = dependency('gtest', main: true)

test(
      'my_vector',
      executable(
        'my_vector_test',
        sources: ['my_vector_test.cc'],
	include_directories: src,
	dependencies: [gtest]
      )
)

