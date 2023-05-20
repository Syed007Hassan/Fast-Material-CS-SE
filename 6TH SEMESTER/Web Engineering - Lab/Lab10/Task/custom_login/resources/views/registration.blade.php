@extends('main')

@section('content')

<div class="row justify-content-center">
	<div class="col-md-4">
		<div class="card">
		<div class="card-header">Registration</div>
		<div class="card-body">
			<form action="{{ route('sample.validate_registration') }}" method="POST">
				@csrf
				<div class="form-group mb-3">
					<input type="text" name="name" class="form-control" placeholder="Name" />
					@if($errors->has('name'))
						<span class="text-danger">{{ $errors->first('name') }}</span>
					@endif
				</div>
				<div class="form-group mb-3">
					<input type="text" name="email" class="form-control" placeholder="Email Address" />
					@if($errors->has('email'))
						<span class="text-danger">{{ $errors->first('email') }}</span>
					@endif
				</div>
				<div class="form-group mb-3">
					<input type="password" name="password" class="form-control" placeholder="Password" />
					@if($errors->has('password'))
						<span class="text-danger">{{ $errors->first('password') }}</span>
					@endif
				</div>
				<div class="d-grid mx-auto">
					<button type="submit" class="btn btn-dark btn-block">Register</button>
				</div>
			</form>
		</div>
	</div>
</div>

@endsection('content')